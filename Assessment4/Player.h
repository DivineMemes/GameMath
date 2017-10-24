#pragma once
#include "transform.h"

class Player
{
public:
	//Bullet bullets[100];
	transform myTrans;
	float Radius;
	Player();
	//In the constructor, disable all bullets
	Player(vec2 pos, vec2 scale, float angle);
	//update all enabled bullets
	
	void update();
	void draw();
};