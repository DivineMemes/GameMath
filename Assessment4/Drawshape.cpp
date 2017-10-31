#include "Drawshape.h"
#include "sfwdraw.h"
void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawAABB(const AABB & box)
{
	float x1 = box.pos.x + box.extents.x;
	float x2 = box.pos.x - box.extents.x;
	float y1 = box.pos.y + box.extents.y;
	float y2 = box.pos.y - box.extents.y;



}
