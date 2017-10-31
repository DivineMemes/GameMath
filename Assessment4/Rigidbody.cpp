#include "Rigidbody.h"

void Rigidbody::integrate(transform & T, float dt)
{
	T.position += velocity * dt;
}
