#pragma once
#include <DxLib.h>
#include <memory>
class ModelLoad;
class Camera;

//////////////////// TO DO
// プレイヤーのインベントリを作るのだ！！！！！


//キャラクターとしてのプレイヤークラス
class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name=""></param>
	void Init(void);
	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name=""></param>
	void Update(void);
	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name=""></param>
	void Draw(void);
private:
	int modelHandl_;
	std::unique_ptr<ModelLoad> load_;
	std::unique_ptr<Camera> camera_;
};

