#pragma once
#include "Vector2.h"
#include <string>
#include <memory>
#include <map>
#include <vector>

#define lpImglMng ImageMng::GetInstance()

/* Z�o�b�t�@�[
�w�i�摜�@0�`9
�}�b�v�`��@10�`19
�L�����N�^�[�@20�`29
FastUI�@30�`39
�}�E�X�̉��ɂق������́@40�`49
�}�E�X�̉��ɂق�������2�@50�`49
�}�E�X�@60�`69
UI�@70�`79
*/

class ImageMng
{
public:
	static ImageMng& GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new ImageMng();
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
	/// �`��\�񂳂ꂽ�摜��`�悳����B
	/// �V�[���̕`�揈���ŕK���Ăяo�����ƁB
	/// </summary>
	/// <param name=""></param>
	void DrawNaw(void);

	/// <summary>
	/// �`��\�񃊃X�g���폜����
	/// ���C�����[�v�̐擪�ŕK���Ăяo�����ƁB
	/// </summary>
	/// <param name=""></param>
	void ReSetD(void);

	/// <summary>
	/// �摜��`�悷��悤�ɗ���
	/// </summary>
	/// <param name="id">�摜�n���h��</param>
	/// <param name="pos">���W</param>
	void GraphAddDrawQue(std::string id, Vector2 pos, int z = 10);

	/// <summary>
	/// �ʃX�N���[����`�悷��悤�ɗ���
	/// </summary>
	/// <param name="id">�X�N���[���n���h��</param>
	void ScreenAddDrawQue(int id, int z = 1);

	/// <summary>
	/// �ʃX�N���[����`�悷��悤�ɗ���
	/// </summary>
	/// <param name="id">�X�N���[���n���h��</param>
	/// <param name="pos">���W</param>
	void ScreenAddDrawQue(int id, Vector2 pos, int z = 10);

	/// <summary>
	/// �摜��ǂݍ��ށB
	/// �Ԃ�l��ID�B�`�悳�������Ƃ��ɕK�v�B
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	/// <returns>ID</returns>
	std::string LoadGraph(std::string fileName);

	/// <summary>
	/// ID�ɑΉ�����ۑ�����Ă���摜���폜����
	/// </summary>
	/// <param name="id">ID</param>
	void DeleteGraph(std::string id);

	/// <summary>
	/// �i�[����Ă���摜�f�[�^�����ׂč폜����B
	/// </summary>
	/// <param name=""></param>
	void ReSetDate(void);

	/// <summary>
	/// ID����摜�n���h�����擾����B
	/// </summary>
	/// <param name="id">ID</param>
	/// <returns>�摜�n���h��</returns>
	int GetGraphHandle(std::string id);

	/// <summary>
	/// ���邳��ݒ�
	/// </summary>
	/// <param name="num">����0~255</param>
	void SetBright(int num);

	/// <summary>
	/// ���邳���擾
	/// </summary>
	/// <returns>���邳</returns>
	int GetBright()const noexcept
	{
		return bright_;
	}

	static void DrawImg(std::string name,Vector2 pos);
private:
	static ImageMng* sInstance;

	std::map<std::string, int> imgList_;	//�ǂݍ��񂾉摜���X�g

	std::vector< std::pair<std::pair<int, int>, Vector2>> drawList_;						//�`��\��L���[//�n���h��&Z�A���W

	int bright_;
	Vector2 screenSize_;
	ImageMng();
	~ImageMng();
};
