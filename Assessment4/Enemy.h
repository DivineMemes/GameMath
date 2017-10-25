#pragma once
#include "transform.h"
#include "Player.h"
class Enemy
{
public:
	transform EnemyTrans;
	Player p;
	float Radius;
	float spdDamper = 10;
	unsigned int textureHandle;
	Enemy();
	Enemy(vec2 pos, vec2 scale, float angle);
	bool enabled = true;
	void update();
	void draw();
	bool CollisionCheck(Player p);
};