#include "mathUtils.h"
#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include<iostream>

int main()
{
	vec3 transform1;
	transform1 = { 8, 3, 5 };

	vec3 transform2;
	transform2 = { 5, 3, 2 };

	vec3 transform3;
	transform3 = { 1, 2, -5 };

	vec3 transform4;
	transform4 = { 7, 2, 4 };

	vec3 result;
	vec3 result2;
	result = 2*transform1;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << result[i] << std::endl;
	}

	result2 = transform3 * 4;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << result2[i] << std::endl;
	}


	mat3 mat1;
	mat3 mat2;

	


	while(true){}
}