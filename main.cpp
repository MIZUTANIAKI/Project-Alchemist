#include <mutex>
#include <thread>
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

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);

	std::unique_ptr<GameSave> gameSave;
	std::unique_ptr<RoadTime> roadTime;
	gameSave = std::make_unique<GameSave>();
	roadTime = std::make_unique<RoadTime>();

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	float Near, Far;
	// Near Far �l�̏�����
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
	int modelHandle = 0;

	std::thread thr(loadModel,"model/Isabel.mv1",&modelHandle);
	thr.detach();

	MV1SetScale(modelHandle, VGet(10.0f, 10.0f, 10.0f));

 	MV1SetPosition(modelHandle, VGet(320.0f, -300.0f, 600.0f));
	
	int count = 0;

	while (ProcessMessage() == 0)
	{  
		// �㉺�̃L�[���͂� Far �𑀍�
		if (CheckHitKey(KEY_INPUT_UP) == 1)
		{
			Far += 20.0f;
		}
		if (CheckHitKey(KEY_INPUT_DOWN) == 1)
		{
			Far -= 20.0f;
		}
		// ���E�̃L�[�� Near �𑀍�
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			Near -= 20.0f;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			Near += 20.0f;
		}
		// Near �̒l�� 0.0f �ȉ��ɂȂ��Ă�����␳
		if (Near <= 0.0f) Near = 10.0f;

		// Far �̒l�� Near ��菬�����Ȃ��Ă�����␳
		if (Far <= Near) Far = Near + 10.0f;

		// Near, Far �N���b�v�̋�����ݒ�
		SetCameraNearFar(Near, Far);

		ClsDrawScreen();
		DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

		if (loadF)
		{
			MV1DrawModel(modelHandle);
			// ���f����������ς��ĂW�`��
			for (int i = 0; i < 8; i++)
			{
				// ���f���̍��W��ݒ�
				MV1SetPosition(modelHandle, VGet(320.0f, 180.0f, 100.0f + i * 400.0f));

				// ���f���̕`��
				MV1DrawModel(modelHandle);
			}
		}
		else
		{
			roadTime->Update(count);
			roadTime->Draw(count);
		}
		// ��ʍ���� Near �̒l�� Far �̒l��`��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Near %f  Far %f", Near, Far);

		ScreenFlip();
		count++;
	}
	MV1DeleteModel(modelHandle);
	DxLib::DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}