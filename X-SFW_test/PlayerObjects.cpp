#include "PlayerObjects.h"

bool doCollision(Paddle & paddle, const Wall & wall)
{
	auto hit = collides(paddle.transform, paddle.collider, wall.transform, wall.collider);
		if (hit.penetrationDepth > 0)
		{
			static_resolution(paddle.transform.position, paddle.rb.velocity, hit,0);
			return true;
		}
		return false;
}

bool doCollision(Ball & ball, const Wall & wall)
{
	auto hit = collides(ball.transform, ball.collider, wall.transform, wall.collider);
	if (hit.penetrationDepth > 0)
	{
		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit, 0);
		return true;
	}
	return false;
}

bool doCollision(Paddle & paddle, Ball & ball)
{
	Collision hit = collides(paddle.transform, paddle.collider, ball.transform, ball.collider);
	if (hit.penetrationDepth > 0)
	{

		static_resolution(ball.transform.position, ball.rigidbody.velocity, hit, 1.2f);

		ball.rigidbody.velocity = 
					(rotate(rand() % 30 - 15) * vec3 { ball.rigidbody.velocity.x,
													   ball.rigidbody.velocity.y, 0 }).xy;

		//dynamic_resolution(paddle.transform.position, paddle.rb.velocity, paddle.rb.mass += 1000000, ball.transform.position, ball.rigidbody.velocity, ball.rigidbody.mass = 1, hit, 1);
		/*float curVel = mag(ball.rigidbody.velocity);
		if (curVel < 0)
		{
			ball.rigidbody.force -= { 1000, 0 };
		}
		else
		{
			ball.rigidbody.force += { 1000, 0 };
		}
		
		ball.rigidbody.velocity *= -1;*/
	}
	return false;
}
