#include "Transform.h"

Transform::Transform()
{
	vec2 position = vec2{ 0,0 };
	dimension = vec2{ 0,0 };
	angle = 0;
	e_parent = nullptr;
}

// translation, scale,  rotation
mat3 Transform::getLocalTransform() const
{
	return translate(position)*scale(dimension)*rotate(angle);
}

mat3 Transform::getGlobalTransform() const
{
	if (e_parent != nullptr)
	{
		return e_parent->getGlobalTransform()*getLocalTransform();
	}
	else
	{
		return getLocalTransform();
	}
}

void DrawMatrix(const mat3 & t, float drawing_scale)
{
	int x = 0;
	vec2 pos = t[2].xy;
	vec2 right_ep = pos + t[0].xy * drawing_scale;
	vec2 up_ep = pos + t[1].xy * drawing_scale;


	sfw::drawLine(pos.x, pos.y, right_ep.x, right_ep.y, RED);
	sfw::drawLine(pos.x, pos.y, up_ep.x, up_ep.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
	sfw::drawCircle(sfw::getMouseX(), sfw::getMouseY(), 10);
}
