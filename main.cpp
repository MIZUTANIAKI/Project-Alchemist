#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <malloc.h>
#include "DxLib.h"
#include <mutex>
#include <thread>
#include "GameSave.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	std::unique_ptr<GameSave> gameSave;
	gameSave = std::make_unique<GameSave>();

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	float Near, Far;
	// Near Far 値の初期化
	Near = 100.0f;
	Far = 2000.0f;
	bool loadF = false;
	bool loadFIn = false;
	std::mutex mtx;
	auto loadModel = [&](std::string filename,int* modelHandle) {
		loadF = false;
		{
			mtx.lock();
			*modelHandle = MV1LoadModel(filename.c_str());
			mtx.unlock();
		}
		loadF = true;
	};



	//int modelHandle = MV1LoadModel("model/RearAlice_3.0.mv1");
	int modelHandle;
	std::thread thr(loadModel,"model/RearAlice_3.0.mv1",modelHandle);
	thr.detach();


	MV1SetScale(modelHandle, VGet(10.0f, 10.0f, 10.0f));

 	MV1SetPosition(modelHandle, VGet(320.0f, -300.0f, 600.0f));

	while (ProcessMessage() == 0)
	{  
		// 上下のキー入力で Far を操作
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			Far += 20.0f;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			Far -= 20.0f;
		}
		// 左右のキーで Near を操作
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Near -= 20.0f;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Near += 20.0f;
		}
		// Near の値が 0.0f 以下になっていたら補正
		if (Near <= 0.0f) Near = 10.0f;

		// Far の値が Near より小さくなっていたら補正
		if (Far <= Near) Far = Near + 10.0f;

		// Near, Far クリップの距離を設定
		SetCameraNearFar(Near, Far);

		ClsDrawScreen();
		DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
		MV1DrawModel(modelHandle);
		// モデルを距離を変えて８個描画
		for (int i = 0; i < 8; i++)
		{
			// モデルの座標を設定
			MV1SetPosition(modelHandle, VGet(320.0f, 180.0f, 100.0f + i * 400.0f));

			// モデルの描画
			MV1DrawModel(modelHandle);
		}
		// 画面左上に Near の値と Far の値を描画
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Near %f  Far %f", Near, Far);

		ScreenFlip();
	}
	MV1DeleteModel(modelHandle);
	DxLib::DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}