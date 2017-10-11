#pragma once
#include "math.h"
float sqr(float v);
float dbl(float v);
float cube(float v);
float degToRad(float deg);
float radToDeg(float rad);

//
float quad(float x);

//takes a start and end point and a time
float lerp(float s, float e, float t);

//takes 2 points and finds the distance
float dist(float x2, float x1, float y2, float y1);
float planePointDist(float a, float b, float c, float d, float x, float y, float z);
