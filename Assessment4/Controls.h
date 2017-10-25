#pragma once
#include "transform.h"
#include "sfwdraw.h"

class MyMouse
{
public:
	bool RisDown = false;
	bool Raction = false;
	bool LisDown = false;
	bool Laction = false;
	MyMouse();
	float mX = sfw::getMouseX();
	float mY = sfw::getMouseY();
	float prevmX;
	float prevmY;
	float savedPosX;
	float savedPosY;
	void Cursor();


	bool LMouseIsDown();
	bool RMouseIsDown();
};



void movement(transform &player);
void lookAtMouse(transform &player);
