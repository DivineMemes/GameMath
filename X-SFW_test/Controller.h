#pragma once
#include "RigidBody.h"

class Controller
{
public:
	void poll(Rigidbody &rb, const Transform &t)
	{
		if (sfw::getKey('W'))
		{
			rb.force += t.getGlobalTransform()[1].xy * 10;
		}

		if (sfw::getKey('Q'))
		{
			rb.torque += 360;
		}
		if (sfw::getKey('E'))
		{
			rb.torque += -360;
		}
		/*if (sfw::getKey('W'))
		{
		rigidbody.force += { 0, 100 };
		}
		if (sfw::getKey('S'))
		{
		rigidbody.force += { 0, -100 };
		}
		if (sfw::getKey('A'))
		{
		rigidbody.force += { -100, 0 };
		}
		if (sfw::getKey('D'))
		{
		rigidbody.force += { 100, 0 };
		}*/
	}
};