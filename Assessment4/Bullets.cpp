#include "Bullets.h"
#include "Controls.h"
#include "Player.h"
#include "Enemy.h"
Bullet::Bullet()
{
	bTrans.radius = 15;
	Radius = 5;
	textureHandle = sfw::loadTextureMap("res/realitycheck.png");
}

Bullet::Bullet(vec2 pos, vec2 scale, float angle) : Bullet()
{
	bTrans.position = pos;
	bTrans.dimension = scale;
	bTrans.angle = angle;
	textureHandle = sfw::loadTextureMap("res/realitycheck.png");
}

void Bullet::update()
{
	bTrans.position += dir * speed;
	lifetime -= sfw::getDeltaTime();
	if (lifetime < 0)
	{
		enabled = false;
	}
}

void Bullet::draw()
{
	sfw::drawTexture(textureHandle, bTrans.position.x, bTrans.position.y, Radius *10, Radius *10);
	//sfw::drawCircle(bTrans.position.x, bTrans.position.y, Radius);
	//DrawMatrix(bTrans.getGlobalTransform(), bTrans.radius);	
}

bool Bullet::CheckCollision(Enemy e)
{
	if (dist(bTrans.position, e.EnemyTrans.position) < Radius + e.Radius)
	{
		return true;
	}
	else
		return false;
}

void Bullet::OnSpawn(Player p)
{
	bTrans.position = p.myTrans.position;
	speed = 15;
	lifetime = 2;
	enabled = true;
	mat3 t = p.myTrans.getGlobalTransform();
	dir = t[0].xy;
}
