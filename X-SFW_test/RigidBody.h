#pragma once
#include "vec2.h"
#include "transform.h"

// Dinosaurs are great!

class Rigidbody
{
public:
	vec2 velocity,
		acceleration,
		force,
		impulse;
	float mass, drag;

	float angularVelocity, angularAcceleration, torque;
	float angulardrag;
	Rigidbody() : velocity{ 0,0 },
		acceleration{ 0,0 },
		force{ 0,0 },
		impulse{ 0,0 },
		mass(1),
		drag(1),
		angularVelocity(0),
		angularAcceleration(0),
		torque(0),
		angulardrag(0.25f)
	{

	}

	//void integrate(Transform &T, float dt);

	void integrate(Transform &T, float dt)
	{
		acceleration = force / mass;
		velocity += acceleration *dt + impulse / mass;
		T.position += velocity * dt;
		impulse = { 0,0 };
		force = -velocity * drag;

		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration *dt;
		T.angle += angularVelocity*dt;
		torque = -angularVelocity *angulardrag;

	}
};