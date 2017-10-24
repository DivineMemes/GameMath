#include "Player.h"

Player::Player(vec2 pos, vec2 scale, float angle)
{
	myTrans.position = pos;
	myTrans.dimension = scale;
	myTrans.angle = angle;
}
void Player::update()
{
	mat3 myMatrix = myTrans.getGlobalTransform();
	vec2 Dir = norm(myMatrix[1].xy);
}
void Player::draw()
{
	sfw::drawCircle(myTrans.position.x, myTrans.position.y, 1);
}