#include <iostream>
#include <ctime>
#include "sfwdraw.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Shapes.h"
#include "DrawShape.h"
#include "Collision.h"
#include "PlayerObjects.h"
int main()
{
	sfw::initContext(800, 600);
	unsigned int doot = sfw::loadSound("doot.wav");
	unsigned int p1Font = sfw::loadTextureMap("fontmap.png", 16, 16);
	int p1s = 48;
	int p2s = 48;
	std::srand(std::time(0));
	float randFX = rand() % 2;
	if (randFX == 0) randFX -= 1;
	std::cout << randFX << std::endl;
	//if (randFX == 0)
	//{
	//	int randDet = rand() % 2;
	//	if (randDet == 1)
	//	{
	//		randFX + 1;
	//	}
	//	else
	//	{
	//		randFX - 1;
	//	}
	//}
	//std::cout << randFX << " ";
	
	float randFY = rand() % 50 - 25;
	Wall wall1;
	wall1.transform.dimension = vec2{ 90,90 };
	wall1.transform.position = vec2{ 400, 600 };
	wall1.collider.box.extents = vec2{ 5, .5 };

	Wall wall2;
	wall2.transform.dimension = vec2{ 90,90 };
	wall2.transform.position = vec2{ 400, 0 };
	wall2.collider.box.extents = vec2{ 5, .5 };

	Wall p1Score;
	p1Score.transform.dimension = vec2{ 10,10 };
	p1Score.transform.position = vec2{ 800, 300 };
	p1Score.collider.box.extents = vec2{ .5, 50 };

	Wall p2Score;
	p2Score.transform.dimension = vec2{ 10,10 };
	p2Score.transform.position = vec2{ 0, 300 };
	p2Score.collider.box.extents = vec2{ .5, 50 };

	Ball ball;
	ball.transform.dimension = vec2{ 10, 10 };
	ball.transform.position = vec2{ 400, 300 };
	ball.sprite.handle = sfw::loadTextureMap("nootella.jpg");
	ball.rigidbody.drag = 0;
	ball.rigidbody.force = vec2{ 50 * randFX,randFY };
	ball.enabled = true;
	
	

	Paddle p1;
	p1.transform.dimension = vec2{ 10, 10 };
	p1.transform.position = vec2{ 100, 300 };
	p1.collider.box.extents = vec2{ 1, 10 };
	p1.controller.up = 'W';
	p1.controller.down = 'S';
	p1.controller.left = 'J';
	p1.controller.right = 'L';
	
	Paddle p2;
	p2.transform.dimension = vec2{ 10, 10 };
	p2.transform.position = vec2{ 700, 300 };
	p2.collider.box.extents = vec2{ 1, 10 };
	p2.controller.up = 'I';
	p2.controller.down = 'K';
	p2.controller.left = 'A';
	p2.controller.right = 'D';

	while (sfw::stepContext())
	{

		float dt = sfw::getDeltaTime();
		///update controllers
		p1.controller.poll(p1.rb, p1.transform);
		p2.controller.poll(p2.rb, p2.transform);
		const char p1ScoreSet[] = { p1s, '\0' };
		const char p2ScoreSet[] = { p2s, '\0' };
		///update rigid bodies
		p1.rb.integrate(p1.transform, dt);
		p2.rb.integrate(p2.transform, dt);
		if (ball.enabled)
			ball.rigidbody.integrate(ball.transform, dt);
		std::cout << ball.rigidbody.velocity.x <<  " " << ball.rigidbody.velocity.y << std::endl;

		///draw
		drawAABB(wall1.collider.getGlobalBox(wall1.transform), WHITE);
		drawAABB(wall2.collider.getGlobalBox(wall2.transform), WHITE);
		drawAABB(p1Score.collider.getGlobalBox(p1Score.transform), WHITE);
		drawAABB(p2Score.collider.getGlobalBox(p2Score.transform), WHITE);
		drawAABB(p1.collider.getGlobalBox(p1.transform), BLUE);
		drawAABB(p2.collider.getGlobalBox(p2.transform), BLUE);
		//string
		sfw::drawString(p1Font, p1ScoreSet,	  0, 600, 50, 50, 0, 0, BLUE);
		sfw::drawString(p1Font, p2ScoreSet, 750, 600, 50, 50, 0, 0, BLUE);

		if (ball.enabled)
		{
			ball.sprite.draw(ball.transform);
			ball.rigidbody.velocity.x = clamp(ball.rigidbody.velocity.x, 0, 500);
			ball.rigidbody.velocity.y = clamp(ball.rigidbody.velocity.y, 0, 500);
		}
		else if (ball.enabled == false)
		{
			ball.transform.dimension = vec2{ 10, 10 };
			ball.transform.position = vec2{ 400, 300 };
			ball.rigidbody.force = vec2{ 50 * randFX,randFY };
			ball.enabled = true;
		}
		///collision

		doCollision(p1, ball, doot);
		doCollision(p2, ball, doot);
		doCollision(p1, wall1);
		doCollision(p1, wall2);
		doCollision(p2, wall1);
		doCollision(p2, wall2);
		doCollision(ball, wall1);
		doCollision(ball, wall2);

		if (doCollision(ball, p1Score) == true)
		{
			p1s++;
			ball.enabled = false;
		}
		if (doCollision(ball, p2Score) == true)
		{
			p2s++;
			ball.enabled = false;
		}
	}
	sfw::termContext();
}