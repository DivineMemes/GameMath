#include <iostream>
#include <ctime>
#include "sfwdraw.h"
#include "WyattsPlayer.h"
#include "Wall.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Shapes.h"
#include "DrawShape.h"
#include "Collision.h"
int main()
{
	sfw::initContext(800, 600);
	/*std::srand(std::time(0));
	float t = 0;
	int j = 0;
	float child_offsetX = 0;
	float child_offsetY = 0;
	Transform myT;
	Rigidbody rigidbody;
	myT.position = vec2{ 400, 300 };
<<<<<<< HEAD
	myT.dimension = vec2{ 100,150 };
	circle c = { {0,0}, 1 };
	circle x = { {100,60}, 50 };
	AABB box = { {0,0}, {1,1} };

	AABB box2 = { {400, 300}, {160, 160} };*/
	WPlayer player;
	player.transform.dimension = vec2{ 64,64 };
	player.transform.position = vec2{ 400, 400 };
	player.collider.box.extents = vec2{ .5,.5 };

	Wall wall;
	wall.transform.dimension = vec2{ 90,90 };
	wall.transform.position = vec2{ 400, 100 };
	wall.collider.box.extents = vec2{ .5, .5 };

	while (sfw::stepContext())
	{

		float dt = sfw::getDeltaTime();
		//update controllers
		player.controller.poll(player.rigidbody, player.transform);
		//update rigid bodies
		player.rigidbody.integrate(player.transform, dt);
		//draw
		drawAABB(player.collider.getGlobalBox(player.transform), MAGENTA);
		DrawMatrix(player.transform.getGlobalTransform(), 1);

		doCollision(player, wall);
		drawAABB(wall.collider.getGlobalBox(wall.transform), WHITE);






		//if (myT.angle >= 360)
		//{
		//	myT.angle = 0;
		//}
		////angle reset

		//DrawMatrix(someT.getGlobalTransform(), 100);
		//
		////crazy stuff
		//for (j = 0; j < 10; ++j)
		//{
		//	DrawMatrix(babyT[j].getGlobalTransform(), 30);
		//	babyT[j].angle += sfw::getDeltaTime() * 100;
		//	if (babyT[j].angle >= 360)
		//	{
		//		babyT[j].angle = 0;
		//	}

		//	if (myT.angle >= -1)
		//	{
		//		sfw::drawLine(myT.angle, babyT[j].angle, myT.angle,babyT[j].position.y);
		//		
		//	}
		//}
		//
		//
		//myT.angle += 2 * sfw::getTime() * sfw::getDeltaTime();
		//		
		////myT.dimension = vec2{ sinf(t) + 100, sinf(t) + 133 };
		//Controls(myT);
		//myT.dimension = vec2{ sinf(t) + 200 * sfw::getDeltaTime(), sinf(t) + sfw::getTime() };
		//std::cout << myT.angle << std::endl;*/
		//float dt = sfw::getDeltaTime();
		////Collision result = intersect_AABB(myT.getGlobalTransform() * box, box2);
		//Collision result2 = intersect_circle(myT.getGlobalTransform() * c, x);
		////unsigned color = result.penetrationDepth <= 0 ? WHITE : RED;
		////if (result.penetrationDepth >= 0)
		////{
		//	//myT.position += result.axis * result.handedness * result.penetrationDepth;
		////}
		////drawAABB(box2, color);
		//if (result2.penetrationDepth >= 0)
		//	{
		//	myT.position += result2.axis * result2.handedness * result2.penetrationDepth;
		//	}
		//drawCircle(x);
		//drawCircle(myT.getGlobalTransform() * c);
		////rigidbody.force += { 0,-25 };

		//rigidbody.integrate(myT, dt);
		//DrawMatrix(myT.getGlobalTransform(), 1);		
	}
	sfw::termContext();
}