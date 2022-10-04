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
	/// 実行処理
	/// </summary>
	/// <param name=""></param>
	void Run(void);

private:
	const Vector2 ScreenSize;		//画面サイズ

	static SceneMng* sInstance;		//シーンマネージャーの静的な宣言
	bool SysInit();					//初期化処理
	UNBS activeScene_;				//今動いてるsceneが入る。

	/// <summary>
	/// 描画関連
	/// </summary>
	/// <param name=""></param>
	void Draw(void);
	SceneMng();
	~SceneMng();
};