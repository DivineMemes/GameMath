#include "mathUtils.h"
#include <cmath>

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
	//return a < b ? a : b;
}

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

float snap(float s, float v, float l)
{
	return abs(v - s) < abs(v - l) ? s : l;
}

int clamp(int value, int min, int max)
{
	if (value < min)
	{
		return min;
	}
	else if (value > max)
	{
		return max;
	}
	return value;
}


float lerpf(const float &s, const float &e, float a)
{
	return s + a * (e - s);
}