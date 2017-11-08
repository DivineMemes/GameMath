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

	/*std::srand(std::time(0));*/
	Wall wall1;
	wall1.transform.dimension = vec2{ 90,90 };
	wall1.transform.position = vec2{ 400, 600 };
	wall1.collider.box.extents = vec2{ 5, 0 };


	Wall wall2;
	wall2.transform.dimension = vec2{ 90,90 };
	wall2.transform.position = vec2{ 400, 0 };
	wall2.collider.box.extents = vec2{ 5, 0 };

	Ball ball;
	ball.transform.dimension = vec2{ 10, 10 };
	ball.transform.position = vec2{ 400, 300 };
	ball.sprite.handle = sfw::loadTextureMap("nootella.jpg");
	ball.rigidbody.drag = 0;
	ball.rigidbody.force = vec2{ 50,0 };

	Paddle p1;
	p1.transform.dimension = vec2{ 10, 10 };
	p1.transform.position = vec2{ 100, 300 };
	p1.collider.box.extents = vec2{ 1, 10 };
	p1.controller.up = 'W';
	p1.controller.down = 'S';
	p1.controller.left = 'A';
	p1.controller.right = 'D';
	
	Paddle p2;
	p2.transform.dimension = vec2{ 10, 10 };
	p2.transform.position = vec2{ 700, 300 };
	p2.collider.box.extents = vec2{ 1, 10 };
	p2.controller.up = 'I';
	p2.controller.down = 'K';
	p2.controller.left = 'J';
	p2.controller.right = 'L';

	while (sfw::stepContext())
	{

		float dt = sfw::getDeltaTime();
		///update controllers
		p1.controller.poll(p1.rb, p1.transform);
		p2.controller.poll(p2.rb, p2.transform);
		
		
		///update rigid bodies
		p1.rb.integrate(p1.transform, dt);
		p2.rb.integrate(p2.transform, dt);
		ball.rigidbody.integrate(ball.transform, dt);

		
		///draw
		//drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		//DrawMatrix(player.transform.getGlobalTransform(), 1);
		drawAABB(wall1.collider.getGlobalBox(wall1.transform), WHITE);
		drawAABB(wall2.collider.getGlobalBox(wall2.transform), WHITE);
		
		drawAABB(p1.collider.getGlobalBox(p1.transform), BLUE);
		drawAABB(p2.collider.getGlobalBox(p2.transform), BLUE);
		ball.sprite.draw(ball.transform);
		
		///collision
		
			doCollision(p1, ball);
			doCollision(p2, ball);
			doCollision(p1, wall1);
			doCollision(p1, wall2);
			doCollision(p2, wall1);
			doCollision(p2, wall2);
		





	}
	sfw::termContext();
}