#include <iostream>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"
#include "PlayerFunctions.h"

int main()
{
	sfw::initContext(800, 600);
	std::srand(std::time(0));
	float t = 0;
	int j = 0;
	float child_offsetX = 0;
	float child_offsetY = 0;
	Transform myT;
	myT.position = vec2{ 400, 300 };
	myT.dimension = vec2{ 1,1 };

	
	Transform babyT[10];
	for (int i = 0; i < 10; ++i)
	{
		babyT[i].position = vec2{ child_offsetX , child_offsetY };
		babyT[i].dimension = vec2{ 1,1 };
		babyT[i].e_parent = &myT;
		child_offsetX += 1;
		child_offsetY += 2;
	}
	Transform someT;
	someT.position = vec2{ 10, 10 };
	someT.dimension = vec2{ 1,1 };
	someT.e_parent = &myT;
	while (sfw::stepContext())
	{
		DrawMatrix(myT.getLocalTransform(), 40);

		if (myT.angle >= 360)
		{
			myT.angle = 0;
		}
		//angle reset

		DrawMatrix(someT.getGlobalTransform(), 100);
		
		//crazy stuff
		for (j = 0; j < 10; ++j)
		{
			DrawMatrix(babyT[j].getGlobalTransform(), 30);
			babyT[j].angle += sfw::getDeltaTime() * 100;
			if (babyT[j].angle >= 360)
			{
				babyT[j].angle = 0;
			}

			if (myT.angle >= -1)
			{
				sfw::drawLine(myT.angle, babyT[j].angle, myT.angle,babyT[j].position.y);
				
			}
		}
		
		
		myT.angle += 2 * sfw::getTime() * sfw::getDeltaTime();
				
		//myT.dimension = vec2{ sinf(t) + 100, sinf(t) + 133 };
		Controls(myT);
		myT.dimension = vec2{ sinf(t) + 200 * sfw::getDeltaTime(), sinf(t) + sfw::getTime() };
		std::cout << myT.angle << std::endl;



	}
		sfw::termContext();
}
