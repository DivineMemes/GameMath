#pragma once
#include "vec3.h"
union mat3
{

	vec3 c[3];
	float m[9];
	float mm[3][3];//[col(y)][row(x)]

	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;
	static mat3 identity();
	static mat3 zero();
	/*
	[10x]x axis
	[01y]y axis
	[001]translation, position



	[0 3 6]
	[1 4 7]
	[2 5 8]

	[(0,0)(0,1)(0,2)]
	[()()()]
	[()()()]


	[c1 c2 c3]

	*/

};

bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &B);

mat3 transpose(const mat3 &A);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 translate(const vec2 &t);

mat3 scale(const vec2 &s);

mat3 rotate(float deg);