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
	bool enabled = false;
	int speed;
	float Radius;
	vec2 dir;
	float lifetime;
	void update();
	void draw();
	bool CheckCollision(Enemy e);
	void OnSpawn(Player p);
};