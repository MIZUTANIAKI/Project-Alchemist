#pragma once
#include "BaseScene.h"
#include "../common/Vector2.h"

#define lpSceneMng SceneMng::GetInstance()

class SceneMng
{
public:

	static SceneMng& GetInstance(void)
	{

		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMng();
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
	/// ���s����
	/// </summary>
	/// <param name=""></param>
	void Run(void);

private:
	const Vector2 ScreenSize;		//��ʃT�C�Y

	static SceneMng* sInstance;		//�V�[���}�l�[�W���[�̐ÓI�Ȑ錾
	bool SysInit();					//����������
	UNBS activeScene_;				//�������Ă�scene������B

	/// <summary>
	/// �`��֘A
	/// </summary>
	/// <param name=""></param>
	void Draw(void);
	SceneMng();
	~SceneMng();
};