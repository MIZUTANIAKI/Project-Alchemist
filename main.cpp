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
	SaveFileD save;
	gameSave->WriteDate(save);
	gameSave->LoadDate();

	bool loadData = false;

	while (ProcessMessage()==0)
	{
		if (gameSave->CheckLoadFinish() && loadData == false)
		{
			loadData = true;
			save = gameSave->GetDate();
		}
		ClsDrawScreen();
		DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
		int y = 0;
		std::string outputDate;
		if (loadData)
		{
			DrawFormatString(0, y, 0xffffff, "%d", save.gameStoryID);
			y += 20;
			for (auto date : save.playerEquipment)
			{
				std::ostringstream oss;
				oss << date.second;
				outputDate = outputDate + oss.str() + ",";
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
			y += 20;
			for (auto date : save.playerItem)
			{
				std::ostringstream oss;
				oss << date.second;
				outputDate = outputDate + oss.str() + ",";
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
			y += 20;
			for (auto date : save.farmChipDate)
			{
				std::ostringstream oss;
				oss << date;
				outputDate = outputDate + oss.str() + ",";
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
			y += 20;
			for (auto date : save.dailyQuest)
			{
				std::ostringstream oss;
				oss << date;
				outputDate = outputDate + oss.str() + ",";
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
			y += 20;
			for (auto date : save.upgradeResult)
			{
				std::ostringstream oss;
				oss << date.second;
				outputDate = outputDate + oss.str() + ",";
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
			y += 20;
			int npcID = 0;
			for (auto npc : save.npcEquipment)
			{
				std::ostringstream toss;
				toss << npcID;
				outputDate = outputDate + "[" + toss.str() + "]:";
				for (auto date : npc.second)
				{
					std::ostringstream oss;
					oss << date.second;
					outputDate = outputDate + oss.str() + ",";
				}
			}
			DrawFormatString(0, y, 0xffffff, "%s", outputDate.c_str());
		}
		ScreenFlip();
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}