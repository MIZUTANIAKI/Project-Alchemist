#pragma once
#include <DxLib.h>
#include <memory>
class ModelLoad;
class Camera;

//////////////////// TO DO
// �v���C���[�̃C���x���g�������̂��I�I�I�I�I


//�L�����N�^�[�Ƃ��Ẵv���C���[�N���X
class Player
{
public:
	Player();
	~Player();

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name=""></param>
	void Init(void);
	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name=""></param>
	void Update(void);
	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name=""></param>
	void Draw(void);
private:
	int modelHandl_;
	std::unique_ptr<ModelLoad> load_;
	std::unique_ptr<Camera> camera_;
};

