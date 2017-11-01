#include "WyattsPlayer.h"

WPlayer::WPlayer()
{
}

bool doCollision(WPlayer & player, Wall & wall)
{
	auto hit = collides(player.transform, player.collider, wall.transform, wall.collider);
	if (hit.penetrationDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit, .25f);
		return true;
	}
	return false;
}
