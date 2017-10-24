#include<iostream>
#include<cstdlib>
#include <cmath>
#include <ctime>
#include "sfwdraw.h"
#include "transform.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullets.h"
#include "Controls.h"
#include "vec2.h"
#include "mat3.h"
int main()
{
	sfw::initContext(800, 600);
	srand (time(NULL));
	float t = 0;
	int j = 0;
	float child_offsetX = 0;
	float child_offsetY = 0;

	Player player(vec2{ 400,300 }, vec2{ 1,1 }, 0);
	
	float spOffsetX = player.myTrans.position.x;
	float spOffsetY = player.myTrans.position.y;
	
	Enemy enemy[10];
	for (int j = 0; j < 10; ++j)
	{
		(vec2{ 0,0 }, vec2{ 1,1 }, 0);
	}

	Bullet bullet[10];
	for (int j = 0; j < 10; ++j)
	{
		(vec2{ 0,0 }, vec2{ 1,1 }, 0);
	}
	MyMouse mouse;
	for(int i = 0; i < 10; ++i)
	{
		if (enemy[i].enabled)
		{
			float randomX = (rand() % (int)(spOffsetX + 800) - 400);
			float randomY = (rand() % (int)(spOffsetY + 600) - 300);
			float distance = dist(player.myTrans.position, vec2{ randomX,randomY });
			if (distance < 150)
			{
				randomX += 200;
				randomY += 200;
			}
			enemy[i].EnemyTrans.position = vec2{ randomX, randomY };
		}
	}	
		
	while (sfw::stepContext())
	{
		//sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 5, YELLOW);
		
		for (int i = 0; i < 10; ++i)
		{
			if (enemy[i].enabled)
			{
				for (int j = 0; j < 10; ++j)
				{
					DrawMatrix(enemy[j].EnemyTrans.getLocalTransform(), 40);
				}
			}
		}
		
		DrawMatrix(player.myTrans.getLocalTransform(), 40);
		
		
		if (mouse.MouseIsDown() == true)
		{
			for (int i = 0; i < 10; ++i)
			{
				bullet[i].enabled;
			}

		}
		movement(player.myTrans);
		lookAtMouse(player.myTrans);
		std::cout << player.myTrans.angle << std::endl;
	}
	sfw::termContext();
}