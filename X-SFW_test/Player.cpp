#include "Player.h"
#include <cstdlib>
#include "sfwdraw.h"

int timer = 0;
void Player::update()
{
	vec2 movement{ 0,0 };
	int xRand = std::rand() % 800 + 1;
	int yRand = std::rand() % 600 + 1;


	if (sfw::getKey('W'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 1;
	}

	if (sfw::getKey(' '))
	{
		movement *= speed;
	}

	if (sfw::getKey('Q') && timer <= 0)
	{
		pos.x = xRand;
		pos.y = yRand;
		timer += 60;
	}
	if (timer > 0)
	{
		timer--;
	}
	pos += movement;
}

void Player::draw()
{


	sfw::drawCircle(pos.x, pos.y, 30.f);

}
