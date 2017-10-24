#pragma once
#include "transform.h"
class Enemy
{
public:
	transform EnemyTrans;
	Enemy();
	Enemy(vec2 pos, vec2 scale, float angle);
	bool enabled = true;
	void update();
	void draw();
};