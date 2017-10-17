#include "mat3.h"
#include "mathUtils.h"
#include <cmath>

vec3& mat3::operator[](size_t idx)
{
	return c[idx]; 
}

const vec3& mat3::operator[](size_t idx) const
{
	return c[idx];
}

mat3 mat3::identity()
{
	return mat3{1,0,0,
				0,1,0,
				0,0,1};
}

mat3 mat3::zero()
{
	return mat3{0,0,0,
				0,0,0,
				0,0,0};
}


bool operator==(const mat3 &A, const mat3 &B)
{
	mat3 matrix;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (abs(A.mm[i][j]) - abs(B.mm[i][j]) < EPSILON)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	mat3 matrix;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (abs(A.mm[i][j]) - abs(B.mm[i][j]) < EPSILON)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

mat3 transpose(const mat3 &A)
{
	mat3 retval;
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			retval[x][y] = A[y][x];
		}
		
	}
	return retval;
}

mat3 operator+(const mat3 &A, const mat3 &B)
{
	
	mat3 matrix;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix.mm[i][j] = A.mm[i][j] + B.mm[i][j];
		}
	}

	return matrix;
}

mat3 operator-(const mat3 &A, const mat3 &B)
{
	mat3 matrix;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix.mm[i][j] = A.mm[i][j] - B.mm[i][j];
		}
	}

	return matrix;
}

//R[m][n] = dot(a[M], B[N])
mat3 operator*(const mat3 &A, const mat3 &B)
{
	mat3 retval;
	mat3 At = transpose(A);
	for (int y = 0; y < 3; y++)
	
		for (int x = 0; x < 3; ++x)
		
			retval[y][x] = dot3(At[x], B[y]);
		
	
	return retval;
}

vec3 operator*(const mat3 &A, const vec3 &B)
{
	mat3 At = transpose(A);

	return vec3 { dot3(At[0],B),
				  dot3(At[1],B),
				  dot3(At[2],B) };
}


float determinant(const mat3 &A)
{
	return dot3(A[0], cross(A[1], A[2]));
}

mat3 inverse(const mat3 &A)
{
	float di = 1 / determinant(A);


	return transpose(mat3{cross(A[1], A[2])*di, cross(A[2], A[0])*di, cross(A[0], A[1])*di});
}

mat3 translate(const vec2 & t)
{
	mat3 retval = mat3::identity();
	retval[2].xy = t;
	return retval;
}

mat3 scale(const vec2 & s)
{
	return mat3{s.x, 0, 0,
				  0, s.y,0,
				  0, 0, 1 };
}

mat3 rotate(float deg)
{
	float rads = deg *3.14 / 180;
	return mat3{ cos(rads),sin(rads),0,
				-sin(rads),cos(rads),0,
				  0,       0,        1};
}
