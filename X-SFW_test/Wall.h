#pragma once
#include "Transform.h"
#include "Sprite.h"
#include "Collider.h"
#include "vec2.h"

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};