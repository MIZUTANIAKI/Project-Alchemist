#include "Player.h"
#include "ModelLoad.h"
#include "Camera.h"

Player::Player()
{
	modelHandl_ = -1;
	Init();
}

Player::~Player()
{
	MV1DeleteModel(modelHandl_);
}

void Player::Init(void)
{
	//������

	//���f���̃��[�h�J�n
	load_ = std::make_unique<ModelLoad>();
	load_->Load(&modelHandl_, "model/Isabel.mv1");

	MV1SetScale(modelHandl_, VGet(10.0f, 10.0f, 10.0f));

	MV1SetPosition(modelHandl_, VGet(320.0f, -300.0f, 600.0f));

	//camera�̍쐬
	camera_ = std::make_unique<Camera>();
}

void Player::Update(void)
{
	if (load_->IsLoadFIn())
	{
		camera_->Update(modelHandl_);
	}
}

void Player::Draw(void)
{
	if (load_->IsLoadFIn())
	{
		MV1DrawModel(modelHandl_);
	}
}
