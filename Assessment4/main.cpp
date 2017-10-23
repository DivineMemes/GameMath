#include <cmath>
#include<iostream>
#include "Controls.h"
#include "sfwdraw.h"
#include "vec2.h"
#include "mat3.h"
#include "transform.h"
int main()
{
	sfw::initContext(800, 600);
	
	float t = 0;
	int j = 0;
	float child_offsetX = 0;
	float child_offsetY = 0;
	transform Player;
	Player.position = vec2{ 400, 300 };
	Player.dimension = vec2{ 1,1 };


	transform babyT[10];
	for (int i = 0; i < 10; ++i)
	{
		babyT[i].position = vec2{ child_offsetX , child_offsetY };
		babyT[i].dimension = vec2{ 1,1 };
		babyT[i].e_parent = &Player;
		child_offsetX += 1;
		child_offsetY += 2;
	}
	
	while (sfw::stepContext())
	{
		DrawMatrix(Player.getLocalTransform(), 40);

		if (Player.angle >= 360)
		{
			Player.angle = 0;
		}
		

		

		//crazy stuff
		for (j = 0; j < 10; ++j)
		{
			DrawMatrix(babyT[j].getGlobalTransform(), 30);
			babyT[j].angle += sfw::getDeltaTime() * 100;
			if (babyT[j].angle >= 360)
			{
				babyT[j].angle = 0;
			}

			if (Player.angle >= -1)
			{
				sfw::drawLine(Player.angle, babyT[j].angle, Player.angle, babyT[j].position.y);

			}
		}


		Player.angle += 2 * sfw::getTime() * sfw::getDeltaTime();

		//myT.dimension = vec2{ sinf(t) + 100, sinf(t) + 133 };
		movement(Player);
		Player.dimension = vec2{ sinf(t) + 200 * sfw::getDeltaTime(), sinf(t) + sfw::getTime() };
		std::cout << Player.angle << std::endl;



	}
	sfw::termContext();
}













































