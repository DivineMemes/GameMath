#include "Drawshape.h"
#include "sfwdraw.h"
void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawVecLine(const vec2 & a, const vec2 & b, unsigned int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y);
}



void drawAABB(const AABB & box,unsigned int color)
{
	vec2 TR = box.pos + box.extents;
	vec2 BL = box.pos - box.extents;
	vec2 BR = { TR.x, BL.y };
	vec2 TL = { BL.x, TR.y };


	drawVecLine(TR, TL, color);
	drawVecLine(TL, BL, color);
	drawVecLine(BL, BR, color);
	drawVecLine(BR, TR, color);
}