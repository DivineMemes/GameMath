#include "Controls.h"

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
}
