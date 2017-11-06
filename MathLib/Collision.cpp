#include "..\X-SFW_test\Collision.h"

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;
	float lPD = Bmax - Amin;
	float rPD = Amax - Bmin;

	ret.penetrationDepth = min(lPD, rPD);
	ret.handedness = copysign(1, rPD - lPD);
	return ret;
}

Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersect_1D(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersect_1D(A.min().y, A.max().y, B.min().y, B.max().y);
	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };
	return xres.penetrationDepth < yres.penetrationDepth ? xres : yres;
}

Collision intersect_circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis = norm(B.position - A.position);
	ret.handedness = 1;
	float Ap = dot(ret.axis, A.position);
	float Bp = dot(ret.axis, B.position);
	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;
	
	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	ret.penetrationDepth = intersect_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;
	return ret;
}

Collision intersect_AABB_circle(const AABB & B, const circle & A)
{
	vec2 cp = snap(B.min(), A.position, B.max());

	Collision result = intersect_circle(A, circle{ cp,0 });
	
}

void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit, float elasticity)
{
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	vel = -reflect(vel, hit.axis*hit.handedness) * elasticity;
}

void dynamic_resolution(vec2 & Apos, vec2 & Avel, float Amass, 
						vec2 & Bpos, vec2 & Bvel, float Bmass,
						const Collision & hit, float elasticity)
{
	//Law of Conservation
	/*
		mass*vel = momentum
		AP + BP = `AP + `BP
		AV - BV = -(`BV - `AV) //Conservation of momentum
		Avel*Amass + Bvel*Bmass = fAvel*Amass + fBvel*Bmass
		Avel - Bvel = -(fBvel - fAvel)
		fBvel = Bvel - Avel + fAvel
	
	*/
	vec2 normal = hit.axis*hit.handedness;
	vec2 Rvel = Avel - Bvel;
	dot(Rvel, normal);
	-(1 + elasticity) * dot(Rvel, normal) / dot(normal, normal *(1 / Amass + 1 / Bmass));


	float j = 0;

	Avel += (j / Amass)*normal;
	Bvel - +(j / Bmass)*normal;

	Apos += normal * hit.penetrationDepth * Amass/ (Amass + Bmass);
	Bpos -= normal * hit.penetrationDepth * Bmass/ (Amass + Bmass);
}