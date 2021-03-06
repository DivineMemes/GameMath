#pragma once
#include "vec2.h"
#include "mat3.h"
#include "sfwdraw.h"
class transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	int radius;
	transform *e_parent;
	transform();


	bool enabled = true;


	mat3 getLocalTransform()const;
	mat3 getGlobalTransform()const;
};

void DrawMatrix(const mat3 &t, float drawing_scale);