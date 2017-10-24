#include "Enemy.h"

Enemy::Enemy()
{
	EnemyTrans.position = vec2{ 0,0 };
	EnemyTrans.dimension = vec2{ 0,0 };
}
Enemy::Enemy(vec2 pos, vec2 scale, float angle)
{
	EnemyTrans.position = pos;
	EnemyTrans.dimension = scale;
	EnemyTrans.angle = angle;
}
void Enemy::update()
{
	mat3 myMatrix = EnemyTrans.getGlobalTransform();
	vec2 Dir = norm(myMatrix[1].xy);
}
void Enemy::draw()
{
	sfw::drawCircle(EnemyTrans.position.x, EnemyTrans.position.y, 15);
}