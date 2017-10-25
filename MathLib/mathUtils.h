#pragma once
int min(int a, int b);
int max(int a, int b);

int clamp(int value, int min, int max);

float lerpf(const float &s, const float &e, float a);

#define EPSILON 0.0000001