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
	//���b�N�m�F
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

	//���b�N
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = false;
	}
	
	//�ǂݍ��݊J�n
	{
		std::lock_guard<std::mutex> lock(savedateMtx_);
		//�����ɃZ�[�u�f�[�^�ǂݍ��ݏ���

	}

	//�ǂݍ��ݏI���@���b�N����
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = true;
	}
}

void GameSave::WritingSaveDate()
{
	//���b�N�m�F
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

	//���b�N
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = false;
	}

	//�������݊J�n
	{
		std::lock_guard<std::mutex> lock(savedateMtx_);
		//�����ɃZ�[�u�f�[�^�������ݏ���
	}

	//�������ݏI���@���b�N����
	{
		std::lock_guard<std::mutex> lock(dateFinishMtx_);
		isDateFinish_ = true;
	}
}
