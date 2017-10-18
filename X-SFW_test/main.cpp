#include <iostream>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"
#include "Transform.h"

int main()
{
	sfw::initContext(800, 600);
	std::srand(std::time(0));
	float t = 0;
	Transform myT;
	myT.position = vec2{ 400, 300 };
	myT.dimension = vec2{ 1,1 };
	while (sfw::stepContext())
	{
		DrawMatrix(myT.getLocalTransform(), 40);
		myT.angle += 1;
		if (myT.angle > 90)
		{
			myT.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };
		}
		else if (myT.angle < 90)
		{
			myT.dimension = vec2{ sinf(t) - 2, sinf(t) - 2 };
		}
	}
		sfw::termContext();
}
