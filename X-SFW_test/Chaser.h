#pragma once
#include "vec2.h"

class ChasePointer
{
public:
	vec2 pos;
	float baseSpeed;
	float speed;


	void update();
	void draw();


};
