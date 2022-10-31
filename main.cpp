#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <malloc.h>
#include "DxLib.h"
#include "GameSave.h"
#include "RoadTime.h"
#include "Player.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	std::unique_ptr<GameSave> gameSave;
	std::unique_ptr<Player> player;
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	gameSave = std::make_unique<GameSave>();
	player = std::make_unique<Player>();

	SetBackgroundColor(123, 123, 123);

	//float camNear, camFar;
	//camNear = 100.0f;
	//camFar = 2000.0f;

	int count = 0;

	//SetUseZBufferFlag(TRUE);

	while (ProcessMessage() == 0)
	{
		//プレイヤー更新
		player->Update();

		//// Near/Far
		//if (CheckHitKey(KEY_INPUT_UP) == 1)
		//{
		//	camFar += 20.0f;
		//}
		//if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		//{
		//	camFar -= 20.0f;
		//}
		//if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		//{
		//	camNear -= 20.0f;
		//}
		//if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		//{
		//	camNear += 20.0f;
		//}
		//if (camNear <= 0.0f) camNear = 10.0f;
		//if (camFar <= camNear) camFar = camNear + 10.0f;

		////クリップ調節
		//SetCameraNearFar(camNear, camFar);

		ClsDrawScreen();
		//ガイド線を描画
		{
			VECTOR pos1;
			VECTOR pos2;
			for (int x = 0; x < 30; x++)
			{
				for (int z = 0; z < 30; z++)
				{
					pos1 = VGet(x * 100 - 1000, 0, z * 100 - 1000);
					pos2 = VGet(x * 100 + 1000, 0, z * 100 - 1000);
					DrawLine3D(pos1, pos2, 0xff);
					pos1 = VGet(x * 100 - 1000, 0, z * 100 - 1000);
					pos2 = VGet(x * 100 - 1000, 0, z * 100 + 1000);
					DrawLine3D(pos1, pos2, 0xff0000);
				}
			}
		}

		//プレイヤー描画
		player->Draw();

		// 点を打つ
		DrawPixel(320, 240, GetColor(255, 255, 255));
		//クロスカーソルを描画
		DrawLine(320, 240 - 20, 320, 240 + 20, 0xff0000);
		DrawLine(320 - 20, 240, 320 + 20, 240, 0xff0000);

		//// 画面左上に Near の値と Far の値を描画
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "Near %f  Far %f", camNear, camFar);

		ScreenFlip();
		count++;
	}
	DxLib::DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}