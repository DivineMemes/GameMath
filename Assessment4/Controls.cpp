#include <cmath>
#include <iostream>
#include "Bullets.h"
#include "Controls.h"


Bullet bullet;
void movement(transform & player)
{
	if (sfw::getKey('W'))
	{
		player.position.y += 1;
	}
	if (sfw::getKey('S'))
	{
		player.position.y -= 1;
	}
	if (sfw::getKey('D'))
	{
		player.position.x += 1;
	}
	if (sfw::getKey('A'))
	{
		player.position.x -= 1;
	}



	//stuff for rotation still pending useage
	/*if (sfw::getKey('Q'))
	{
		player.angle += 1;
	}
	if (sfw::getKey('E'))
	{
		player.angle -= 1;
	}*/
}


void lookAtMouse(transform&player)
{
	

	vec2 angleVect = {sfw::getMouseX() - player.position.x, sfw::getMouseY() - player.position.y };
	
	angleVect = norm(angleVect);

	float  angle = atan2(angleVect.y, angleVect.x) * 180/ 3.14159265359;

	player.angle = angle;
}


MyMouse::MyMouse()
{
}

bool MyMouse::MouseIsDown()
{
	if (sfw::getMouseButton(0))
	{
		action = true;
		isDown = true;		
	}
	else
	{
		isDown = false;
	}
	if (action == true && isDown == false)
	{
		return true;
	}
	return false;
}