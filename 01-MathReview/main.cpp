#include<iostream>
#include"mathutils.h"


int main()
{
	float value = sqr(2);
	std::cout << value << std::endl;
	
	float blah = dbl(10);
	std::cout << blah << std::endl;

	float leMath = cube(10);
	std::cout << leMath << std::endl;

	float degs = degToRad(19);
	std::cout << degs << std::endl;

	float radroach = radToDeg(degs);
	std::cout << radroach << std::endl;

	float quadrad = quad(0);
	std::cout << quadrad << std::endl;

	float lerps = lerp(0, 10, 0.5);
	std::cout << lerps << std::endl;

	float distance = dist(0, 0, 2, 0);
	std::cout << distance << std::endl;
	while(true){}
}