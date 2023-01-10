#include "func.h"
#include "common.h"

int Add(int a, int b)
{
	staticValue = 200;

	return a + b;
}

int Sub(int a, int b)
{
	externValue = 300;

	return a - b;
}

int Mul(int a, int b)
{
	return a * b;
}
