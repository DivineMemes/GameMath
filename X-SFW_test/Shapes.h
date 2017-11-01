#pragma once
#include "vec2.h"
#include "mat3.h"
struct circle
{
	vec2 position;
	float radius;
};

struct AABB
{
	vec2 pos;
	vec2 extents;

	vec2 min() const { return pos - extents; };
	vec2 max() const { return pos + extents; };
};
circle operator*(const mat3 &M, const circle &C);
AABB operator*(const mat3 &M, const AABB &B);