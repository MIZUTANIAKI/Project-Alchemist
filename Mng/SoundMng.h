#pragma once
#include <string>
#include <map>
#include <vector>

#define lpSoundMng SoundMng::GetInstance()

class SoundMng
{
public:

	static SoundMng& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SoundMng();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}

	/// <summary>
	/// ������ǂݍ��ށB
	/// �Ԃ�l��ID�B�`�悳�������Ƃ��ɕK�v�B
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	/// <returns>ID</returns>
	void LoadSound(std::string fileName);

	/// <summary>
	/// �������Đ�����
	/// </summary>
	/// <param name="id">�����n���h��</param>
	/// <param name="PlayType">�Đ��^�C�v</param>
	void SoundPlay(std::string id, int PlayType = 0x0001);

	/// <summary>
	/// �������Đ�����Ă��邩���ׂ�
	/// </summary>
	/// <param name="id">ID</param>
	/// <returns>�Đ����Ȃ�true</returns>
	bool CheckPlaySound(std::string id);

	/// <summary>
	/// �Đ����̉������~�߂�
	/// </summary>
	/// <param name="id"></param>
	void StopSound(std::string id);

	/// <summary>
	/// ID�ɑΉ�����ۑ�����Ă��鉹�����폜����
	/// </summary>
	/// <param name="id">ID</param>
	void DeleteSound(std::string id);

	/// <summary>
	/// �i�[����Ă��鉹���f�[�^�����ׂč폜����B
	/// </summary>
	/// <param name=""></param>
	void ReSetDate(void);

	/// <summary>
	/// ID���特���n���h�����擾����B
	/// </summary>
	/// <param name="id">ID</param>
	/// <returns>�����n���h��</returns>
	int GetSoundHandle(std::string id);

	/// <summary>
	/// ���ʂ��Z�b�g����
	/// </summary>
	/// <param name="num">����</param>
	void SetSoundVol(int num);

	/// <summary>
	/// ���ʂ��擾����
	/// </summary>
	/// <param name=""></param>
	/// <returns>����</returns>
	int GetSoundVol(void)const noexcept
	{
		return soundVol_;
	}

private:
private:
	static SoundMng* sInstance;

	std::map<std::string, int> soundList_;	//�ǂݍ��񂾉������X�g

	int soundVol_;

	SoundMng();
	~SoundMng();
};
