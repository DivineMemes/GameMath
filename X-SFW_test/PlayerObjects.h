#pragma once
#include "RigidBody.h"
#include "Transform.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"
#include "vec2.h"

class Paddle
{
public:
	Rigidbody rb;
	Transform transform;
	Controller controller;
	Collider collider;
	Sprite sprite;
	int score = 0;
};

class Ball
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
	bool enabled = true;
};

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};
bool doCollision(Paddle &paddle, const Wall &wall);
bool doCollision(Ball &ball, const Wall &wall);
bool doCollision(Paddle &paddle, Ball &ball, unsigned int sound);