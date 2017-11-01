#pragma once
#include "RigidBody.h"
#include "Transform.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"
#include "vec2.h"
#include "Wall.h"
class WPlayer
{
public:
	WPlayer();
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller controller;
	Sprite sprite;
};
bool doCollision(WPlayer &player, Wall &wall);
