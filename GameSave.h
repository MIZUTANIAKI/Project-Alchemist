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
	/// <summary>
	/// セーブファイルがいくつあるかを調べる
	/// </summary>
	/// <returns></returns>
	int GetSaveFileNum();
	/// <summary>
	/// [引数]番のセーブデータを読み込む初期値は1番データ
	/// </summary>
	/// <param name="num">セーブデータ番号</param>
	void LoadDate(int num = 1);
	/// <summary>
	/// セーブデータ受け取り処理
	/// </summary>
	/// <returns>セーブデータ</returns>
	SaveFileD GetDate();
	/// <summary>
	/// [引数2]番セーブに[引数1]のデータをセーブします。
	/// </summary>
	/// <param name="date">セーブデータ</param>
	/// <param name="num">セーブデータ番号</param>
	void WriteDate(SaveFileD& date, int num = 1);
private:
	SaveFileD savedate_;

	std::map<std::string,bool> saveDataNumber_;

	/// <summary>
	/// セーブデータロード関数本体
	/// </summary>
	/// <param name="num">セーブデータ番号</param>
	void LoadingSaveDate(int num);
	/// <summary>
	/// セーブデータ書き込み関数本体
	/// </summary>
	/// <param name="num">セーブデータ番号</param>
	void WritingSaveDate(int num);
};

