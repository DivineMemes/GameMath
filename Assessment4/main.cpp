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

	int j = 0;
	int reset = 0;
	int radius = 40;
	float t = 0;
	float child_offsetX = 0;
	float child_offsetY = 0;
	MyMouse mouse;

	Player player(vec2{ 400,300 }, vec2{ 1,1 }, 0);
	
	float spOffsetX = player.myTrans.position.x;
	float spOffsetY = player.myTrans.position.y;
	
	Enemy enemy[10];
	

	Bullet bullet[10];
	
	for(int i = 0; i < 10; ++i)
	{
		if (enemy[i].enabled)
		{
			float randomX = (rand() % (int)(spOffsetX + 800) - 400);
			float randomY = (rand() % (int)(spOffsetY + 600) - 300);
			float distance = dist(player.myTrans.position, vec2{ randomX,randomY });
			if (distance < 150)
			{
				randomX += 100;
				randomY += 100;
			}
			enemy[i].EnemyTrans.position = vec2{ randomX, randomY };
			
		}
	}	
		
	while (sfw::stepContext())
	{
		
		for (int i = 0; i < 10; ++i)
		{
			if (enemy[i].enabled)
			{
				for (int j = 0; j < 10; ++j)
				{
					enemy[i].p = player;
					enemy[i].draw();
					enemy[i].update();
				}
			}
		}
		
		player.draw();
		
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i].enabled)
			{
				for (int j = 0; j < 10; j++)
				{
					if (enemy[j].enabled)
					{
						if (bullet[i].CheckCollision(enemy[j]))
						{
							//Do Collision stuff
							bullet[i].enabled = false;
							enemy[j].enabled = false;
							reset++;
						}
					}
				}
			}			
		}


		if (reset >= 10)
		{
			reset = 0;
			for (int i = 0; i < 10; ++i)
			{
				enemy[i].enabled = true;
				float randomX = (rand() % (int)(spOffsetX + 800) - 400);
				float randomY = (rand() % (int)(spOffsetY + 600) - 300);
				float distance = dist(player.myTrans.position, vec2{ randomX,randomY });
				if (distance < 150)
				{
					randomX += 100;
					randomY += 100;
				}
				enemy[i].EnemyTrans.position = vec2{ randomX, randomY };
			}
		}

		
			if (mouse.MouseIsDown())
			{
				for (int i = 0; i < 10; ++i)
				{
					if (bullet[i].enabled == false)
					{
						std::cout << "Mouse Clicked" << std::endl;
						/*bullet[i].enabled;*/

						bullet[i].OnSpawn(player);
						break;
					}
					
				}
			}

		
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i].enabled == true)
			{
				bullet[i].draw();
				bullet[i].update();
			}
			
		}
		movement(player.myTrans);
		lookAtMouse(player.myTrans);
		mouse.Cursor();
		//std::cout << reset << std::endl;
	}
	sfw::termContext();
}