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
	
	float expandDuration = 1.0f;
	float expandTimer = 0.0f;

	/*expandTimer += sfw::getDeltaTime();

	sfw::drawCircle(400, 300, lerpf(0.0f, 300, expandTimer / expandDuration));

	expandTimer = expandTimer > 10.0f ? 10.0f : expandTimer;*/
	void update();
	void draw();
	void OnSpawn(Player p);
};