#include <memory>
#include <ostream>
#include <string>
#include <sstream>
#include <iostream>
#include "DxLib.h"
#include "GameSave.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<GameSave> gameSave;
	gameSave = std::make_unique<GameSave>();

	while (ProcessMessage() == 0)
	{
		ClsDrawScreen();
		DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ

		
		ScreenFlip();
	}

	DxLib::DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}