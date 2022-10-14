#include "GameSave.h"

GameSave::GameSave()
{
}

GameSave::~GameSave()
{
}

void GameSave::LoadDate()
{
}

bool GameSave::CheckLoadFinish()
{
	bool rtnF = true;
	dateFinishMtx_.lock();
	if (isDateFinish_)
	{
		rtnF = false;
	}
	dateFinishMtx_.unlock();
	return rtnF;
}

SaveFileD GameSave::GetDate()
{
	return SaveFileD();
}

void GameSave::WriteDate(SaveFileD& date)
{
}

void GameSave::LoadingSaveDate()
{
	//ロック確認
	do
	{
		dateFinishMtx_.lock();
		if (!isDateFinish_)
		{
			dateFinishMtx_.unlock();
			break;
		}
		dateFinishMtx_.unlock();
	} while (true);

	//ロック
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = false;
	}
	
	//読み込み開始
	{
		std::lock_guard<std::mutex> lock(savedateMtx_);
		//ここにセーブデータ読み込み処理

	}

	//読み込み終了　ロック解除
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = true;
	}
}

void GameSave::WritingSaveDate()
{
	//ロック確認
	do
	{
		dateFinishMtx_.lock();
		if (!isDateFinish_)
		{
			dateFinishMtx_.unlock();
			break;
		}
		dateFinishMtx_.unlock();
	} while (true);

	//ロック
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = false;
	}

	//書き込み開始
	{
		std::lock_guard<std::mutex> lock(savedateMtx_);
		//ここにセーブデータ書き込み処理
	}

	//書き込み終了　ロック解除
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = true;
	}
}
