#pragma once
#include "transform.h"
#include "sfwdraw.h"

class MyMouse
{
public:
	bool isDown = false;
	bool action = false;
	MyMouse();
	float mX = sfw::getMouseX();
	float mY = sfw::getMouseY();
	float prevmX;
	float prevmY;
	float savedPosX;
	float savedPosY;
	void Cursor();
	//float OnMouseDown();

	bool MouseIsDown();
};



void movement(transform &player);
void lookAtMouse(transform &player);
