#include <cmath>
#include <iostream>
#include "Bullets.h"
#include "Controls.h"


void movement(transform & player)
{
	int timer = 10;
	int speed = 2;
	if (sfw::getKey('W'))
	{
		player.position.y += speed;
	}
	if (sfw::getKey('S'))
	{
		player.position.y -= speed;
	}
	if (sfw::getKey('D'))
	{
		player.position.x += speed;
	}
	if (sfw::getKey('A'))
	{
		player.position.x -= speed;
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


void MyMouse::Cursor()
{
	mX = sfw::getMouseX(); mY = sfw::getMouseY();
	sfw::drawCircle(mX, mY, 5);
}

//float MyMouse::OnMouseDown()
//{
//	if (sfw::getMouseButton(0))
//	{
//		action = true;
//		isDown = true;
//		//Button is held down
//	}
//	else
//	{
//		isDown = false;
//		prevmX = sfw::getMouseX();
//		prevmY = sfw::getMouseY();
//		//Button is held up
//	}
//	if (action == true && isDown == false)
//	{
//		savedPosX = prevmX;
//		savedPosY = prevmY;
//		action = false;
//
//	}
//	return (savedPosX, savedPosY);
//}

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
		action = false;
		return true;
	}
	return false;
}