#pragma once
#include "RigidBody.h"
#include "Transform.h"
#include "Collider.h"
#include "Controller.h"
#include "vec2.h"

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
};