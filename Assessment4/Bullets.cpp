#include "Bullets.h"
#include "Controls.h"
Bullet::Bullet()
{
}

Bullet::Bullet(vec2 pos, vec2 scale, float angle)
{
	bTrans.position = pos;
	bTrans.dimension = scale;
	bTrans.angle = angle;
}

void Bullet::update()
{
	mat3 myMatrix = bTrans.getGlobalTransform();
	vec2 Dir = norm(myMatrix[1].xy);
}

void Bullet::draw()
{
	Bullet bullet;
	DrawMatrix(bullet.bTrans.getLocalTransform(), 5);
}
