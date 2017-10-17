#pragma once
#include "vec3.h"
union mat3
{

	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;
	static mat3 identity();
	/*
	[10x]
	[01y]
	[001]



	[0 3 6]
	[1 4 7]
	[2 5 8]

	[(0,0)(0,1)(0,2)]
	[()()()]
	[()()()]


	[c1 c2 c3]

	*/

};



mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const mat3 &B);

mat3 transpose(const mat3 &A);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);