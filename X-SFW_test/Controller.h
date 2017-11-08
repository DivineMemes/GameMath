#pragma once
#include "RigidBody.h"


class Controller
{
public:
	int up, down, left, right;

	void poll(Rigidbody &rb, const Transform &t)
	{
		if (sfw::getKey(up))
		{
			rb.force += { 0, 250 };
		}
		if (sfw::getKey(down))
		{
			rb.force += { 0, -250 };
		}
		if (sfw::getKey(left))
		{
			rb.torque += 360;
		}
		if (sfw::getKey(right))
		{
			rb.torque += -360;
		}
		
		/*
		if (sfw::getKey('W'))
		{
			rb.force += t.getGlobalTransform()[1].xy * 10;
		}

		if (sfw::getKey('W'))
		{
			rb.force += { 0, 100 };
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