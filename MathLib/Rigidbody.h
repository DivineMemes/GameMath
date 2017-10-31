#pragma once
#include "vec2.h"


class Rigidbody
{
public:
	vec2 velocity;

	Rigidbody() : velocity{ 0,0 }
	{

	}


	void integrate(Transform &T, float dt);
};