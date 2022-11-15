#include <math.h>
#include "Camera.h"

// �ړ����x
#define MOVESPEED			10.0f

// �J�����̉�]���x
#define CAMERA_ANGLE_SPEED		3.0f

// �J�����̒����_�̍���
#define CAMERA_LOOK_AT_HEIGHT		200.0f

// �J�����ƒ����_�̋���
#define CAMERA_LOOK_AT_DISTANCE		400.0f

Camera::Camera()
{
	angle_ = 0.0f;
	cameraHAngle_ = 0.0f;
	cameraVAngle_ = 40.0f;
	moveVector_ = VGet(0.0f, 0.0f, 0.0f);
	pos_ = VGet(0.0f, 0.0f, 0.0f);
	moveFlag_ = false;
	SetCameraNearFar(100.0f, 50000.0f);
}

Camera::~Camera()
{
}

void Camera::SetCamera(void)
{
	{
		VECTOR tmpPos1;
		VECTOR TmpPos2;
		VECTOR camPos;
		VECTOR camLoocPos;

		// �����_
		camLoocPos = pos_;
		camLoocPos.y += CAMERA_LOOK_AT_HEIGHT;

		// �J�����̈ʒu���v�Z
		sinNum = sin(cameraVAngle_ / 180.0f * DX_PI_F);
		cosNum = cos(cameraVAngle_ / 180.0f * DX_PI_F);
		tmpPos1.x = 0.0f;
		tmpPos1.y = sinNum * CAMERA_LOOK_AT_DISTANCE;
		tmpPos1.z = -cosNum * CAMERA_LOOK_AT_DISTANCE;

		sinNum = sin(cameraHAngle_ / 180.0f * DX_PI_F);
		cosNum = cos(cameraHAngle_ / 180.0f * DX_PI_F);
		TmpPos2.x = cosNum * tmpPos1.x - sinNum * tmpPos1.z;
		TmpPos2.y = tmpPos1.y;
		TmpPos2.z = sinNum * tmpPos1.x + cosNum * tmpPos1.z;
		camPos = VAdd(TmpPos2, camLoocPos);

		// �J�����̐ݒ�ɔ��f����
		SetCameraPositionAndTarget_UpVecY(camPos, camLoocPos);
	}
}

void Camera::Update(int model)
{
	// �ړ��x�N�g����������
	moveVector_ = VGet(0.0f, 0.0f, 0.0f);
	moveFlag_ = false;

	//�J��������
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		cameraVAngle_ += CAMERA_ANGLE_SPEED;
		if (cameraVAngle_ >= 80.0f)
		{
			cameraVAngle_ = 80.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		cameraVAngle_ -= CAMERA_ANGLE_SPEED;
		if (cameraVAngle_ <= 0.0f)
		{
			cameraVAngle_ = 0.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		cameraHAngle_ += CAMERA_ANGLE_SPEED;
		if (cameraHAngle_ >= 180.0f)
		{
			cameraHAngle_ -= 360.0f;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		cameraHAngle_ -= CAMERA_ANGLE_SPEED;
		if (cameraHAngle_ <= -180.0f)
		{
			cameraHAngle_ += 360.0f;
		}
	}

	// �L�����N�^�[�̈ړ�������ݒ�
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		angle_ = 180.0f - cameraHAngle_;
		moveFlag_ = TRUE;
		moveVector_.z = MOVESPEED;
	}
	//if (CheckHitKey(KEY_INPUT_S) == 1)
	//{
	//	angle_ = 0.0f - cameraHAngle_;
	//	moveFlag_ = TRUE;
	//	moveVector_.z = -MOVESPEED;
	//}
	//if (CheckHitKey(KEY_INPUT_A) == 1)
	//{
	//	angle_ = 90.0f - cameraHAngle_;
	//	moveFlag_ = TRUE;
	//	moveVector_.x = -MOVESPEED;
	//}
	//if (CheckHitKey(KEY_INPUT_D) == 1)
	//{
	//	angle_ = -90.0f - cameraHAngle_;
	//	moveFlag_ = TRUE;
	//	moveVector_.x = MOVESPEED;
	//}

	//�ړ����Ȃ�
	if (moveFlag_ == TRUE)
	{
		VECTOR tmpMoveVec;
		sinNum = sin(cameraHAngle_ / 180.0f * DX_PI_F);
		cosNum = cos(cameraHAngle_ / 180.0f * DX_PI_F);
		tmpMoveVec.x = moveVector_.x * cosNum - moveVector_.z * sinNum;
		tmpMoveVec.y = 0.0f;
		tmpMoveVec.z = moveVector_.x * sinNum + moveVector_.z * cosNum;

		pos_ = VAdd(pos_, tmpMoveVec);
	}

	//������ݒ�
	MV1SetRotationXYZ(model, VGet(0.0f, angle_ / 180.0f * DX_PI_F, 0.0f));

	//���W��ݒ�
	MV1SetPosition(model, pos_);
	
	SetCamera();
}
