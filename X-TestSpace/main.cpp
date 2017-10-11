#include "mathUtils.h"

#include "vec2.h"
int main()
{
	int val = min(1, 3);
	vec2 test;
	test.x = 5;
	test.y = 20;


	vec2 testB;
	testB.x = 13;
	testB.y = 4;

	vec2 result = test + testB;


	vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	vec2 test1;
	test1.x = 2;
	test1.y = 5;


	vec2 test2;
	test2.x = 4;
	test2.y = 8;

	vec2 resultsub = test1 - test2;



	vec2 t1;
	t1.x = 2;
	t1.y = 2;
	

	vec2 t2;
	t2.x = 2;
	t2.y = 2;
	float multi = 3;
	vec2 MultTest = multi * t2;


	vec2 negate;
	negate.x = 3;
	negate.y = 5;

	vec2 negRes = -negate;

	bool iequ = t1 != negate;
	bool equ = t1 != t2;

	bool eq = num == test;
	bool ieq = num == testB;
	vec2 newz = negate / 3.0f;
	
	while(true){}
}