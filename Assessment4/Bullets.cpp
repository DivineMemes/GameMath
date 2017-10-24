#include "Bullets.h"
#include "Controls.h"
#include "Player.h"
#include "Enemy.h"
Bullet::Bullet()
{
	bTrans.radius = 15;
	Radius = 5;
}

Bullet::Bullet(vec2 pos, vec2 scale, float angle) : Bullet()
{
	bTrans.position = pos;
	bTrans.dimension = scale;
	bTrans.angle = angle;
}

void Bullet::update()
{
	//mat3 myMatrix = bTrans.getGlobalTransform();
	//vec2 Dir = norm(myMatrix[1].xy);
	bTrans.position += dir * speed;
	lifetime -= sfw::getDeltaTime();
	if (lifetime < 0)
	{
		enabled = false;
	}
}

void Bullet::draw()
{
	
	//bullet.bTrans.e_parent = &player.myTrans;
	//sfw::drawCircle(bTrans.position.x, bTrans.position.y, 5);
	/*bullet.speed = 1;
	bullet.lifetime = 5;*/
	sfw::drawCircle(bTrans.position.x, bTrans.position.y, Radius);
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
