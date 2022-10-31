#pragma once
#include <mutex>
#include <thread>
#include <string>

//3D���f�������[�h����A��p�N���X
class ModelLoad
{
public:
	ModelLoad();
	~ModelLoad();

	/// <summary>
	/// ���̃N���X��ǂނ��ƂŃ��[�h
	/// </summary>
	/// <param name="handl">�i�[��̃n���h��</param>
	/// <param name="filep">�t�@�C���p�X</param>
	void Load(int* handl,std::string filep);
	/// <summary>
	/// ���[�h���I����Ă��邩�ۂ�
	/// </summary>
	/// <param name=""></param>
	/// <returns>True����������</returns>
	bool IsLoadFIn(void);
private:
	/// <summary>
	/// ���[�h�����{��
	/// </summary>
	/// <param name="modelHandle">�i�[��</param>
	/// <param name="filename">�t�@�C���l�[��</param>
	void LoadNow(int* modelHandle, std::string filename);
	bool loadF = false;
	std::mutex mtx;
};

