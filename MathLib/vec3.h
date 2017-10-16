#pragma once

#include "vec2.h"
union vec3
{
	//access by array

	float v[3];

	//access by individual component

	struct { float x, y, z; };

	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;

	vec2 xy;

};


//takes in 2 vector3's and adds them
vec3 operator+(const vec3 &lhs, const vec3 &rhs);

//takes a vector3 and adds to it
vec3 operator+=(vec3 &lhs, const vec3 &rhs);

//subtracts 2 vector3's
vec3 operator-(const vec3 &lhs, const vec3 &rhs);

//takes in a vector 3 and subtracts from it
vec3 operator-=(vec3 &lhs, const vec3 &rhs);

//multiplies left hand side by a number
vec3 operator*(const vec3 & lhs, const float mult);

//multiplies right hand side by a number
vec3 operator*(const float mult, const vec3 & rhs);

//multiplies the left hand side vector3 by a number
vec3 operator*=(vec3 &lhs, const float &mult);

//multiplies the right hand side vector3 by a number
vec3 operator*=(const float &mult, vec3 &rhs);

//divides a vector3
vec3 operator/(const vec3 &lhs, const float div);

vec3 operator/= (const vec3 &lhs, const float div);

//negates a vector
vec3 operator-(const vec3 &rhs);

//checks if 2 vector3's are equal
bool operator==(const vec3 &lhs, const vec3 &rhs);

//checks if two vector3's are inequal
bool operator!=(const vec3 &lhs, const vec3 &rhs);

//returns the magnitude of a vec3
float mag3(const vec3 &v);

vec3 norm3(const vec3 &v);

vec3 &normalize3(vec3 &v);

float dot3(const vec3 &a, const vec3 &b);

float dist3(const vec3 &a, const vec3 &b);

vec3 min3(const vec3 &a, const vec3 &b);

vec3 max3(const vec3 &a, const vec3 &b);

vec3 clamp(vec3 &v, const vec3 min, const vec3 max);
