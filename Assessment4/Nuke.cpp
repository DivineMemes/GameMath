#include "Nuke.h"
#include "Enemy.h"
#include "mathUtils.h"
Nuke::Nuke()
{
	nTrans.radius = 0;
	Radius = 5;
}

Nuke::Nuke(vec2 pos, vec2 scale, float angle)
{
	nTrans.position = pos;
	nTrans.dimension = scale;
	nTrans.angle = angle;
}

bool Nuke::NukeCollision(Enemy e)
{
	if (dist(nTrans.position, e.EnemyTrans.position) < Radius + e.Radius)
	{
		return true;
	}
	else
		return false;
}

void Nuke::update()
{
	expandTimer += sfw::getDeltaTime();
	Radius = lerpf(0.0f, 50, expandTimer / expandDuration);
	lifetime += sfw::getDeltaTime();
	if (lifetime >= expandDuration)
	{
		enabled = false;
		expandTimer = 0;
		Radius = 0;
	}
}

void Nuke::draw()
{
	sfw::drawCircle(nTrans.position.x, nTrans.position.y, Radius);
}

void Nuke::OnSpawn(Player p)
{
	nTrans.position = p.myTrans.position;
	lifetime = 0;
	enabled = true;
}
