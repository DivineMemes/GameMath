#include "Player.h"

Player::Player()
{
	myTrans.radius = 40;
	Radius = 40;
}

Player::Player(vec2 pos, vec2 scale, float angle) : Player()
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
	sfw::drawCircle(myTrans.position.x, myTrans.position.y, Radius);
	DrawMatrix(myTrans.getLocalTransform(), myTrans.radius);
}