#include "mat3.h"


/*vec3 & mat3::operator[](size_t idx)
{
	
}*/

/*const vec3 & mat3::operator[](size_t idx) const
{
	
}*/

mat3 mat3::identity()
{
	return mat3();
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	
	mat3 matrix;
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++i)
		{
			matrix.mm[i][j] = A.mm[i][j] + B.mm[i][j];
		}
	}

	return matrix;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3();
}

mat3 transpose(const mat3 & A)
{
	return mat3();
}

float determinant(const mat3 & A)
{
	return 0.0f;
}

mat3 inverse(const mat3 & A)
{
	return mat3();
}
