#pragma once

union vec2
{
	//access by array

	//union is 2 floats
	float v[2];


	struct { float x, y; };
	//still 2 floats\
	not 4
	float operator[](int idx) const;
	float operator[](int idx);
};



						//left hand side   right hand side
vec2 operator+(const vec2 &lhs, const vec2 &rhs);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 &operator-=(vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, const float &rhs);

vec2 operator*(const float &lhs, const vec2 &rhs);

vec2 operator*=(vec2 &lhs, const float &rhs);

vec2 operator*=(const float &lhs, vec2 &rhs);

vec2 operator/(const vec2 &lhs, const float &rhs);

vec2 operator/=(vec2 &lhs, const float &rhs);

//negates a vector
vec2 operator-(const vec2 &rhs);

bool operator!=(const vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);



float mag(const vec2 &v);

vec2 norm(const vec2 &v);

vec2 &normalize(vec2 &v);

float dot(const vec2 &a, const vec2 &b);

float dist(const vec2 &a, const vec2 &b);

vec2 perp(const vec2 &v);

vec2 lerp(const vec2 &s, const vec2 &e, float a);

vec2 min(const vec2 &a, const vec2 &b);

vec2 max(const vec2 &a, const vec2 &b);