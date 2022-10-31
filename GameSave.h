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
	//�i�s�x
	unsigned int gameStoryID;
	//����
	std::map<Equipment, int> playerEquipment;
	//�A�C�e��
	std::map<EquipmentItems, int> playerItem;
	//�_�� 6*4=24�}�X
	std::vector<int> farmChipDate;
	//�f�C���[�N�G�X�g 5�܂Ŏ��
	std::vector<int> dailyQuest;
	//�A�b�v�O���[�h��
	std::map<UpgradeResult, int> upgradeResult;
	//����NPC NPCID�ƁA����
	std::map<int, std::map<Equipment, int>> npcEquipment;
	//����
	unsigned int Money;
	//���_�A�C�e��
	std::vector<int> item;
};

enum class SaveDateName
{
	//�i�s�x
	gameStoryID,
	//����
	playerEquipment,
	//�A�C�e��
	playerItem,
	//�_�� 6*4=24�}�X
	farmChipDate,
	//�f�C���[�N�G�X�g 5�܂Ŏ��
	dailyQuest,
	//�A�b�v�O���[�h��
	upgradeResult,
	//����NPC NPCID�ƁA����
	npcEquipment,
	//����
	Money,
	//���_�A�C�e��
	item
};

class GameSave
{
public:
	GameSave();
	void InitGameDate();
	~GameSave();
	/// <summary>
	/// �Z�[�u�t�@�C�����������邩�𒲂ׂ�
	/// </summary>
	/// <returns></returns>
	int GetSaveFileNum();
	/// <summary>
	/// [����]�Ԃ̃Z�[�u�f�[�^��ǂݍ��ޏ����l��1�ԃf�[�^
	/// </summary>
	/// <param name="num">�Z�[�u�f�[�^�ԍ�</param>
	void LoadDate(int num = 1);
	/// <summary>
	/// �Z�[�u�f�[�^�󂯎�菈��
	/// </summary>
	/// <returns>�Z�[�u�f�[�^</returns>
	SaveFileD GetDate();
	/// <summary>
	/// [����2]�ԃZ�[�u��[����1]�̃f�[�^���Z�[�u���܂��B
	/// </summary>
	/// <param name="date">�Z�[�u�f�[�^</param>
	/// <param name="num">�Z�[�u�f�[�^�ԍ�</param>
	void WriteDate(SaveFileD& date, int num = 1);
private:
	SaveFileD savedate_;

	std::map<std::string,bool> saveDataNumber_;

	/// <summary>
	/// �Z�[�u�f�[�^���[�h�֐��{��
	/// </summary>
	/// <param name="num">�Z�[�u�f�[�^�ԍ�</param>
	void LoadingSaveDate(int num);
	/// <summary>
	/// �Z�[�u�f�[�^�������݊֐��{��
	/// </summary>
	/// <param name="num">�Z�[�u�f�[�^�ԍ�</param>
	void WritingSaveDate(int num);
};

