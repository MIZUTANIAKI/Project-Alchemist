#pragma once
#include <DxLib.h>

//�v���C���[�̃J���������ŁA�v���C���[���̂��̂̃N���X
class Camera
{
public:
	Camera();
	~Camera();

	void Update(int model);

	float  cameraHAngle_;
	float  cameraVAngle_;
	VECTOR moveVector_;
	bool moveFlag_;
	float  sinNum;
	float  cosNum;
	float  angle_;
	VECTOR pos_;
private:
	void SetCamera(void);
};

