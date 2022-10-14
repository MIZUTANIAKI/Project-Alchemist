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
	//�i�s�x
	unsigned int gameStoryID;
	//����
	std::map<Equipment, int> playerEquipment;
	//�A�C�e��
	std::map<EquipmentItems, int> playerItem;
	//�_�� 6*4=24�}�X
	std::vector<int> farmChipDate;
	//�f�C���[�N�G�X�g 5�܂Ŏ��
	std::array<int, 5> dailyQuest;
	//�A�b�v�O���[�h��
	std::map<UpgradeResult, int> upgradeResult;
	//����NPC NPCID�ƁA����
	std::map<int, Equipment> npcEquipment;
	//����
	unsigned int Money;
	//���_�A�C�e��
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

