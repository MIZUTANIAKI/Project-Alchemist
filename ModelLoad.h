#pragma once
#include <mutex>
#include <thread>
#include <string>

//3Dモデルをロードする、専用クラス
class ModelLoad
{
public:
	ModelLoad();
	~ModelLoad();

	/// <summary>
	/// このクラスを読むことでロード
	/// </summary>
	/// <param name="handl">格納先のハンドル</param>
	/// <param name="filep">ファイルパス</param>
	void Load(int* handl,std::string filep);
	/// <summary>
	/// ロードが終わっているか否か
	/// </summary>
	/// <param name=""></param>
	/// <returns>True＝完了した</returns>
	bool IsLoadFIn(void);
private:
	/// <summary>
	/// ロード処理本体
	/// </summary>
	/// <param name="modelHandle">格納先</param>
	/// <param name="filename">ファイルネーム</param>
	void LoadNow(int* modelHandle, std::string filename);
	bool loadF = false;
	std::mutex mtx;
};

