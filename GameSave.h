#pragma once
#include <map>
#include <vector>
#include <memory>

enum class Equipment
{
	headEquipmentID,
	bodyEquipmentID,
	legsEquipmentID,
	handEquipmentID,
	mainWeaponID
};

enum class EquipmentItems
{
	item1,
	item2,
	item3,
	item4,
	item5
};

enum class UpgradeResult
{
	alchemyPot,
	alchemyFlask,
	bag,
	city
};

struct SaveFileD
{
	//進行度
	unsigned int gameStoryID;
	//装備
	std::map<Equipment, int> playerEquipment;
	//アイテム
	std::map<EquipmentItems, int> playerItem;
	//農場 6*4=24マス
	std::vector<int> farmChipDate;
	//デイリークエスト 5個まで受諾
	std::vector<int> dailyQuest;
	//アップグレード状況
	std::map<UpgradeResult, int> upgradeResult;
	//味方NPC NPCIDと、装備
	std::map<int, std::map<Equipment, int>> npcEquipment;
	//お金
	unsigned int Money;
	//拠点アイテム
	std::vector<int> item;
};

enum class SaveDateName
{
	//進行度
	gameStoryID,
	//装備
	playerEquipment,
	//アイテム
	playerItem,
	//農場 6*4=24マス
	farmChipDate,
	//デイリークエスト 5個まで受諾
	dailyQuest,
	//アップグレード状況
	upgradeResult,
	//味方NPC NPCIDと、装備
	npcEquipment,
	//お金
	Money,
	//拠点アイテム
	item
};

class GameSave
{
public:
	GameSave();
	void InitGameDate();
	~GameSave();

	int GetSaveFileNum();

	void LoadDate(int num = 1);
	SaveFileD GetDate();

	void WriteDate(SaveFileD& date, int num = 1);
private:
	SaveFileD savedate_;

	std::map<std::string,bool> saveDataNumber_;

	void LoadingSaveDate(int num);
	void WritingSaveDate(int num);
};

