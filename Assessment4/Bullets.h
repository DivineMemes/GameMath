#pragma once
#include "transform.h"
#include "Player.h"
class Enemy;

class Bullet
{
public:
	transform bTrans;
	Bullet();
	Bullet(vec2 pos, vec2 scale, float angle);
	vec2 dir;
	unsigned int textureHandle;
	bool enabled = false;
	bool CheckCollision(Enemy e);
	float Radius;
	float lifetime;
	int speed;
	void update();
	void draw();
	void OnSpawn(Player p);
};