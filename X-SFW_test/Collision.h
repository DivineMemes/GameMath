#pragma once
#include "mathUtils.h"
#include "Shapes.h"
#include <cmath>

struct Collision
{
	float penetrationDepth; //if penetration is negative that = distance
	float handedness; // does A need to move left or right along axis
	vec2 axis;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);
Collision intersect_AABB(const AABB &A, const AABB &B);
Collision intersect_circle(const circle &A, const circle &B);
Collision intersect_AABB_circle(const AABB &A, const circle &B);

//

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity);