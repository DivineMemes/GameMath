#include "vec3.h"
#include "mathUtils.h"
#include <cmath>
#include <cfloat>

float &vec3::operator[](unsigned idx)
{
	return v[idx];
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

vec3 operator+(const vec3 & lhs, const vec3 &rhs)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] + rhs.v[i];
	}

	return result;
}

vec3 operator+=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

vec3 operator-(const vec3 &lhs, const vec3 &rhs)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] - rhs.v[i];
	}
	return result;
}

vec3 operator-=(vec3 &lhs, const vec3 &rhs)
{
	lhs = lhs - rhs;
	return lhs;
}

vec3 operator*(const vec3 &lhs, const float mult)
{
	vec3 result;

	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] * mult;
	}

	return result;
}

vec3 operator*(const float mult, const vec3 &rhs)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = mult * rhs.v[i];
	}
	return result;
}

vec3 operator*=(vec3 &lhs, const float &mult)
{
	for (int i = 0; i < 3; ++i)
	{
		lhs.v[i] = lhs.v[i] * mult;
	}	
	return lhs;
}

vec3 operator*=(const float &mult, vec3 &rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		rhs.v[i] = mult * rhs.v[i];
	}
	return rhs;
}

vec3 operator/(const vec3 &lhs, const float div)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = lhs.v[i] / div;
	}
	return result;
}

vec3 operator/=(vec3 &lhs, const float div)
{
	for (int i = 0; i < 3; ++i)
	{
		lhs.v[i] = lhs.v[i] / div;
	}
	return lhs;
}

bool operator==(const vec3 &lhs, const vec3 &rhs)
{
	if(abs(lhs.x - rhs.x) < FLT_EPSILON && 
		abs(lhs.y - rhs.y) < FLT_EPSILON &&
		abs (lhs.z - rhs.z) < FLT_EPSILON)
	return false;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	for (int i = 0; i < 3; ++i)
	{
		if (lhs.v[i] != rhs.v[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

vec3 operator-(const vec3 & rhs)
{
	vec3 result;
	for (int i = 0; i < 3; ++i)
	{
		result.v[i] = -1 * rhs.v[i];
	}
	
	return result;
}

float mag3(const vec3 & v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;
	float cSqr = v.z * v.z;
	return sqrtf(aSqr + bSqr + cSqr);
}

vec3 norm3(const vec3 & v)
{
	vec3 temp = v;
	float len = mag3(v);
	temp /= len;
	return temp;
}

vec3 & normalize3(vec3 & v)
{
	v = norm3(v);
	return v;
}

float dot3(const vec3 &a, const vec3 &b)
{

	return (a.x * b.x)+(a.y * b.y)+(a.z * b.z);
}

float dist3(const vec3 & a, const vec3 & b)
{
	return mag3(b - a);
}

vec3 min3(const vec3 &a, const vec3 &b)
{
	vec3 temp;
	temp.x = min(a.x, b.x);
	temp.y = min(a.y, b.y);
	temp.z = min(a.z, b.z);
	return temp;
}

vec3 max3(const vec3 &a, const vec3 &b)
{
	vec3 temp;
	temp.x = max(a.x, b.x);
	temp.y = max(a.y, b.y);
	temp.z = max(a.z, b.z);
	return temp;
}

vec3 clamp(vec3 & v, const vec3 min, const vec3 max)
{
	v.x = clamp(v.x, min.x, max.x);
	v.y = clamp(v.y, min.y, max.y);
	v.z = clamp(v.z, min.z, max.z);

	return v;
}
