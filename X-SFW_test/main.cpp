#include <iostream>
#include <ctime>
#include "sfwdraw.h"
#include "Player.h"

int main()
{
	sfw::initContext(800, 600);
	std::srand(std::time(0));

	Player me;
	me.pos = { 400, 300};
	me.speed = 3;
	while (sfw::stepContext())
	{
		me.update();
		me.draw();

	}

	sfw::termContext();
}