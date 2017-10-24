#pragma once
#include "transform.h"
class Bullet
{
public:
	transform bTrans;
	Bullet();
	Bullet(vec2 pos, vec2 scale, float angle);
	bool enabled = false;
	int speed;
	float lifetime;
	void update();
	void draw();
};