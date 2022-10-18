#include <iostream>
#include <sstream>
#include <fstream>
#include "GameSave.h"

GameSave::GameSave()
{
	isDateFinish_ = true;
	InitGameDate();
	savedate_.item.emplace_back(0);
	savedate_.item.emplace_back(120);
	savedate_.item.emplace_back(150);
	savedate_.item.emplace_back(999);
	savedate_.playerEquipment.at(Equipment::headEquipmentID) = 995;
	savedate_.playerEquipment.at(Equipment::bodyEquipmentID) = 996;
	savedate_.playerEquipment.at(Equipment::handEquipmentID) = 997;
	savedate_.playerEquipment.at(Equipment::legsEquipmentID) = 998;
	savedate_.playerEquipment.at(Equipment::mainWeaponID) = 999;
	savedate_.Money = 999999;
}

void GameSave::InitGameDate()
{
	savedate_ = SaveFileD();
	savedate_.gameStoryID = 0;
	savedate_.playerEquipment.try_emplace(Equipment::headEquipmentID, 0);
	savedate_.playerEquipment.try_emplace(Equipment::bodyEquipmentID, 0);
	savedate_.playerEquipment.try_emplace(Equipment::handEquipmentID, 0);
	savedate_.playerEquipment.try_emplace(Equipment::legsEquipmentID, 0);
	savedate_.playerEquipment.try_emplace(Equipment::mainWeaponID, 0);
	savedate_.playerItem.try_emplace(EquipmentItems::item1, 0);
	savedate_.playerItem.try_emplace(EquipmentItems::item2, 0);
	savedate_.playerItem.try_emplace(EquipmentItems::item3, 0);
	savedate_.playerItem.try_emplace(EquipmentItems::item4, 0);
	savedate_.playerItem.try_emplace(EquipmentItems::item5, 0);
	savedate_.farmChipDate.reserve(24);
	savedate_.farmChipDate.emplace_back(0);
	savedate_.dailyQuest.reserve(5);
	savedate_.dailyQuest.emplace_back(0);
	savedate_.upgradeResult.try_emplace(UpgradeResult::alchemyPot, 0);
	savedate_.upgradeResult.try_emplace(UpgradeResult::alchemyFlask, 0);
	savedate_.upgradeResult.try_emplace(UpgradeResult::bag, 0);
	savedate_.upgradeResult.try_emplace(UpgradeResult::city, 0);
	savedate_.npcEquipment.try_emplace(0, savedate_.playerEquipment);
	savedate_.npcEquipment.try_emplace(1, savedate_.playerEquipment);
	savedate_.npcEquipment.try_emplace(2, savedate_.playerEquipment);
	savedate_.npcEquipment.try_emplace(3, savedate_.playerEquipment);
	savedate_.Money = 0;
	savedate_.item.reserve(100);
	savedate_.item.emplace_back(0);
}

GameSave::~GameSave()
{
}

void GameSave::LoadDate()
{
	InitGameDate();
	LoadingSaveDate();
}

bool GameSave::CheckLoadFinish()
{
	return isDateFinish_;
}

SaveFileD GameSave::GetDate()
{
	if (isDateFinish_)
	{
		return savedate_;
	}
	return SaveFileD();
}

void GameSave::WriteDate(SaveFileD& date, int num)
{
	if (isDateFinish_)
	{
		savedate_ = date;
		WritingSaveDate(num);
	}
}

void GameSave::LoadingSaveDate()
{
	isDateFinish_ = false;
	
	//読み込み開始
	{
		//ここにセーブデータ読み込み処理
		std::fstream file;
		//std::fstream gameStoryID, playerEquipment, playerItem, farmChipDate, dailyQuest, upgradeResult, npcEquipment, Money, item;
		file.open("./SaveDate/dat1.sav", std::ios::binary | std::ios::in);
		//gameStoryID.open("./SaveDate/dat1_1.sav", std::ios::binary | std::ios::in);
		//playerEquipment.open("./SaveDate/dat1_2.sav", std::ios::binary | std::ios::in);
		//playerItem.open("./SaveDate/dat1_3.sav", std::ios::binary | std::ios::in);
		//farmChipDate.open("./SaveDate/dat1_4.sav", std::ios::binary | std::ios::in);
		//dailyQuest.open("./SaveDate/dat1_5.sav", std::ios::binary | std::ios::in);
		//upgradeResult.open("./SaveDate/dat1_6.sav", std::ios::binary | std::ios::in);
		//npcEquipment.open("./SaveDate/dat1_7.sav", std::ios::binary | std::ios::in);
		//Money.open("./SaveDate/dat1_8.sav", std::ios::binary | std::ios::in);
		//item.open("./SaveDate/dat1_9.sav", std::ios::binary | std::ios::in);

		file.read((char*)&savedate_.gameStoryID, sizeof(savedate_.gameStoryID));
		file.read((char*)&savedate_.playerEquipment[Equipment::headEquipmentID], sizeof(savedate_.playerEquipment[Equipment::headEquipmentID]));
		file.read((char*)&savedate_.playerEquipment[Equipment::bodyEquipmentID], sizeof(savedate_.playerEquipment[Equipment::bodyEquipmentID]));
		file.read((char*)&savedate_.playerEquipment[Equipment::handEquipmentID], sizeof(savedate_.playerEquipment[Equipment::handEquipmentID]));
		file.read((char*)&savedate_.playerEquipment[Equipment::legsEquipmentID], sizeof(savedate_.playerEquipment[Equipment::legsEquipmentID]));
		file.read((char*)&savedate_.playerEquipment[Equipment::mainWeaponID], sizeof(savedate_.playerEquipment[Equipment::mainWeaponID]));

		file.read((char*)&savedate_.playerItem[EquipmentItems::item1], sizeof(savedate_.playerItem[EquipmentItems::item1]));
		file.read((char*)&savedate_.playerItem[EquipmentItems::item2], sizeof(savedate_.playerItem[EquipmentItems::item2]));
		file.read((char*)&savedate_.playerItem[EquipmentItems::item3], sizeof(savedate_.playerItem[EquipmentItems::item3]));
		file.read((char*)&savedate_.playerItem[EquipmentItems::item4], sizeof(savedate_.playerItem[EquipmentItems::item4]));
		file.read((char*)&savedate_.playerItem[EquipmentItems::item5], sizeof(savedate_.playerItem[EquipmentItems::item5]));

		file.read((char*)&savedate_.farmChipDate[0], sizeof(savedate_.farmChipDate[0]));
		file.read((char*)&savedate_.dailyQuest[0], sizeof(savedate_.dailyQuest[0]));

		file.read((char*)&savedate_.upgradeResult[UpgradeResult::alchemyPot], sizeof(savedate_.upgradeResult[UpgradeResult::alchemyPot]));
		file.read((char*)&savedate_.upgradeResult[UpgradeResult::alchemyFlask], sizeof(savedate_.upgradeResult[UpgradeResult::alchemyFlask]));
		file.read((char*)&savedate_.upgradeResult[UpgradeResult::bag], sizeof(savedate_.upgradeResult[UpgradeResult::bag]));
		file.read((char*)&savedate_.upgradeResult[UpgradeResult::city], sizeof(savedate_.upgradeResult[UpgradeResult::city]));

		for (int i = 0; i < 4; i++)
		{
			file.read((char*)&savedate_.npcEquipment[i][Equipment::headEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::headEquipmentID]));
			file.read((char*)&savedate_.npcEquipment[i][Equipment::bodyEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::bodyEquipmentID]));
			file.read((char*)&savedate_.npcEquipment[i][Equipment::handEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::handEquipmentID]));
			file.read((char*)&savedate_.npcEquipment[i][Equipment::legsEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::legsEquipmentID]));
		}

		file.read((char*)&savedate_.Money, sizeof(savedate_.Money));
		file.read((char*)&savedate_.item[0], sizeof(savedate_.item[0]));

		//gameStoryID.close();
		//playerEquipment.close();
		//playerItem.close();
		//farmChipDate.close();
		//dailyQuest.close();
		//upgradeResult.close();
		//npcEquipment.close();
		//Money.close();
		//item.close();

		file.close();

		//savefile.open("Log.txt", std::ios::in);
		//std::string fileDateLine;
		//int datecounter = 0;
		//while (std::getline(savefile, fileDateLine,';')) {
		//	std::cout << fileDateLine << std::endl;
		//	std::ifstream dateline(fileDateLine);
		//	std::string date;
		//	int counter = 0;
		//	while (std::getline(dateline, date, ':'))
		//	{
		//		SaveDataInput(static_cast<SaveDateName>(datecounter), date, counter);
		//		counter++;
		//	}
		//	datecounter++;
		//}
	}

	//読み込み終了
	isDateFinish_ = true;
}

void GameSave::WritingSaveDate(int num))
{
	isDateFinish_ = false;

	//書き込み開始
	{
		//ここにセーブデータ書き込み処理
		std::fstream file;
		//std::fstream gameStoryID, playerEquipment, playerItem, farmChipDate, dailyQuest, upgradeResult, npcEquipment, Money, item;
		std::string filename = "./SaveDate/dat"+  num + ".sav";
		file.open("./SaveDate/dat.sav", std::ios::binary | std::ios::out);
		//gameStoryID.open("./SaveDate/dat1_1.sav", std::ios::binary | std::ios::out);
		//playerEquipment.open("./SaveDate/dat1_2.sav", std::ios::binary | std::ios::out);
		//playerItem.open("./SaveDate/dat1_3.sav", std::ios::binary | std::ios::out);
		//farmChipDate.open("./SaveDate/dat1_4.sav", std::ios::binary | std::ios::out);
		//dailyQuest.open("./SaveDate/dat1_5.sav", std::ios::binary | std::ios::out);
		//upgradeResult.open("./SaveDate/dat1_6.sav", std::ios::binary | std::ios::out);
		//npcEquipment.open("./SaveDate/dat1_7.sav", std::ios::binary | std::ios::out);
		//Money.open("./SaveDate/dat1_8.sav", std::ios::binary | std::ios::out);
		//item.open("./SaveDate/dat1_9.sav", std::ios::binary | std::ios::out);

		file.write((char*)&savedate_.gameStoryID, sizeof(savedate_.gameStoryID));
		file.write((char*)&savedate_.playerEquipment[Equipment::headEquipmentID], sizeof(savedate_.playerEquipment[Equipment::headEquipmentID]));
		file.write((char*)&savedate_.playerEquipment[Equipment::bodyEquipmentID], sizeof(savedate_.playerEquipment[Equipment::bodyEquipmentID]));
		file.write((char*)&savedate_.playerEquipment[Equipment::handEquipmentID], sizeof(savedate_.playerEquipment[Equipment::handEquipmentID]));
		file.write((char*)&savedate_.playerEquipment[Equipment::legsEquipmentID], sizeof(savedate_.playerEquipment[Equipment::legsEquipmentID]));
		file.write((char*)&savedate_.playerEquipment[Equipment::mainWeaponID], sizeof(savedate_.playerEquipment[Equipment::mainWeaponID]));

		file.write((char*)&savedate_.playerItem[EquipmentItems::item1], sizeof(savedate_.playerItem[EquipmentItems::item1]));
		file.write((char*)&savedate_.playerItem[EquipmentItems::item2], sizeof(savedate_.playerItem[EquipmentItems::item2]));
		file.write((char*)&savedate_.playerItem[EquipmentItems::item3], sizeof(savedate_.playerItem[EquipmentItems::item3]));
		file.write((char*)&savedate_.playerItem[EquipmentItems::item4], sizeof(savedate_.playerItem[EquipmentItems::item4]));
		file.write((char*)&savedate_.playerItem[EquipmentItems::item5], sizeof(savedate_.playerItem[EquipmentItems::item5]));

		file.write((char*)&savedate_.farmChipDate[0], sizeof(savedate_.farmChipDate[0]));
		file.write((char*)&savedate_.dailyQuest[0], sizeof(savedate_.dailyQuest[0]));

		file.write((char*)&savedate_.upgradeResult[UpgradeResult::alchemyPot], sizeof(savedate_.upgradeResult[UpgradeResult::alchemyPot]));
		file.write((char*)&savedate_.upgradeResult[UpgradeResult::alchemyFlask], sizeof(savedate_.upgradeResult[UpgradeResult::alchemyFlask]));
		file.write((char*)&savedate_.upgradeResult[UpgradeResult::bag], sizeof(savedate_.upgradeResult[UpgradeResult::bag]));
		file.write((char*)&savedate_.upgradeResult[UpgradeResult::city], sizeof(savedate_.upgradeResult[UpgradeResult::city]));

		for (int i = 0; i < 4; i++)
		{
			file.write((char*)&savedate_.npcEquipment[i][Equipment::headEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::headEquipmentID]));
			file.write((char*)&savedate_.npcEquipment[i][Equipment::bodyEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::bodyEquipmentID]));
			file.write((char*)&savedate_.npcEquipment[i][Equipment::handEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::handEquipmentID]));
			file.write((char*)&savedate_.npcEquipment[i][Equipment::legsEquipmentID], sizeof(savedate_.npcEquipment[i][Equipment::legsEquipmentID]));
		}

		file.write((char*)&savedate_.Money, sizeof(savedate_.Money));
		file.write((char*)&savedate_.item[0], sizeof(savedate_.item[0]));

		//gameStoryID.close();
		//playerEquipment.close();
		//playerItem.close();
		//farmChipDate.close();
		//dailyQuest.close();
		//upgradeResult.close();
		//npcEquipment.close();
		//Money.close();
		//item.close();
		file.close();
	}

	//書き込み終了
	isDateFinish_ = true;
}
