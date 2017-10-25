#pragma once
#include "transform.h"

class Player
{
public:
	
	transform myTrans;
	float Radius;
	Player();
	Player(vec2 pos, vec2 scale, float angle);
	void update();
	void draw();
};