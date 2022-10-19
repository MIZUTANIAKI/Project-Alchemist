#include <memory>
#include <ostream>
#include <string>
#include <sstream>
#include <iostream>
#include "DxLib.h"
#include "GameSave.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	std::unique_ptr<GameSave> gameSave;
	gameSave = std::make_unique<GameSave>();

	while (ProcessMessage() == 0)
	{
		ClsDrawScreen();
		DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

		
		ScreenFlip();
	}

	DxLib::DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}