#pragma once
#include "vec2.h"
#include "transform.h"

class Rigidbody
{
public:
	vec2 velocity;

	Rigidbody() : velocity{ 0,0 }
	{

	}

	void integrate(transform &T, float dt);

	/*void integrate(transform &T, float dt)
	{
		T.position += velocity * dt;
	}*/
};