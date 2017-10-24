#include <cmath>
#include "Enemy.h"
Enemy::Enemy()
{
	EnemyTrans.radius = 40;
	Radius = 10;
	EnemyTrans.dimension = vec2{ 1,1 };
	EnemyTrans.angle = 0;
}
Enemy::Enemy(vec2 pos, vec2 scale, float angle) : Enemy()
{
	EnemyTrans.position = pos;
	EnemyTrans.dimension = scale;
	EnemyTrans.angle = angle;
}
void Enemy::update()
{
	
	mat3 myMatrix = EnemyTrans.getGlobalTransform();
	vec2 Dir = norm(myMatrix[1].xy);

	if (dist(p.myTrans.position, EnemyTrans.position) > 0)
	{
		vec2 angleVect = p.myTrans.position - EnemyTrans.position;
		angleVect = norm(angleVect);
		float angle = atan2(angleVect.y, angleVect.x) * 180 / 3.14159265359;
		EnemyTrans.angle = angle;
		EnemyTrans.position += angleVect/spdDamper;
	}
}



void Enemy::draw()
{
	sfw::drawCircle(EnemyTrans.position.x, EnemyTrans.position.y, Radius);
	//DrawMatrix(EnemyTrans.getLocalTransform(), EnemyTrans.radius);
}

bool Enemy::CollisionCheck(Player p)
{
	if (dist(EnemyTrans.position, p.myTrans.position) < Radius + p.Radius)
	{
		return true;
	}
	else
		return false;
}
