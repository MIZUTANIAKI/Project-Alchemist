#pragma once
#include <DxLib.h>

//プレイヤーのカメラ処理で、プレイヤーそのもののクラス
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

