#include "mathutils.h"
#include <cmath>
float sqr(float v)
{
	return v * v;
}

float dbl(float v)
{
	return v*2;
}

float cube(float v)
{
	return v*v*v;
}

float degToRad(float deg)
{
	return (deg * 3.14)/180;
}

float radToDeg(float rad)
{
	return (rad * 180)/3.14;
}

float quad(float x)
{
	return sqr(x) + 2*x - 7;
}

float lerp(float s, float e, float t)
{
	return s + t * (e-s);
}

float dist(float x2, float x1, float y2, float y1)
{
	float p1 = sqr(x2 - x1);
	float p2 = sqr(y2 - y1);

	return sqrt((p1) + (p2));
}

float planePointDist(float a, float b, float c, float d, float x, float y, float z)
{
	float p = (a*x + b*y + c*z + d);
	float x = sqrt(sqr(a) + sqr(b) + sqr(c));

	return  p / x;
}
