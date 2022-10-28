#pragma once
#include "Vector2.h"

class RoadTime
{
public:
	RoadTime();
	~RoadTime();

	void Update(float deltaTime);

	void Draw(float deltaTime);
	void Init(void);

private:
	int screenH_;
	Vector2 screenSize_;

	float rsita_;
	int time_;
};
