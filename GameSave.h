#pragma once
#include <map>
#include <vector>
#include <array>
#include <memory>
#include <thread>
#include <mutex>

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
	std::array<int, 5> dailyQuest;
	//アップグレード状況
	std::map<UpgradeResult, int> upgradeResult;
	//味方NPC NPCIDと、装備
	std::map<int, Equipment> npcEquipment;
	//お金
	unsigned int Money;
	//拠点アイテム
	std::vector<int> item;
};

class GameSave
{
public:
	GameSave();
	~GameSave();

	void LoadDate();
	bool CheckLoadFinish();
	SaveFileD GetDate();

	void WriteDate(SaveFileD& date);
private:
	SaveFileD savedate_;
	std::mutex savedateMtx_;

	bool isDateFinish_;
	std::mutex dateFinishMtx_;

	void LoadingSaveDate();
	void WritingSaveDate();
};

