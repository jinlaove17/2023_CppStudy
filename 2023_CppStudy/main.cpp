#include <stdio.h>

int RecursiveFactorial(int n);
int RecursiveFibonacci(int n);

int main()
{
	// 재귀 함수: 가독성, 구현 용이, 성능 저하
	int n = RecursiveFactorial(10);

	printf("%d\n", n);

	n = RecursiveFibonacci(10);

	printf("%d\n", n);
}

int RecursiveFactorial(int n)
{
	if (n == 1)
	{
		return 1;
	}

	return n * RecursiveFactorial(n - 1);
}

// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
int RecursiveFibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}
