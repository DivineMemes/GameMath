#pragma once
#include "transform.h"
#include "Player.h"
class Enemy;

class Nuke
{
public:
	transform nTrans;
	Nuke();
	Nuke(vec2 pos, vec2 scale, float angle);
	bool enabled = false;
	bool NukeCollision(Enemy e);
	float Radius;
	float lifetime;
	
	float expandDuration = 1.5f;
	float expandTimer = 0.0f;
	void update();
	void draw();
	void OnSpawn(Player p);
};