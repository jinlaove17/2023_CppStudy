// <단축키>
// 지정 영역 주석 처리: Ctrl + k + c
// 지정 영역 주석 해제: Ctrl + k + u
// 세로 블럭 지정: Alt + Drag
// 디버깅 시작: F5
// 디버깅 중, 다음 중단점까지 실행: F5
// 중단점 지정 및 해제: F9
// 프로시저 단위 실행: F10
// 한 단계씩 코드 실행: F11
// 디버깅 종료하기: Shift + F5

#include <stdio.h>

// 함수
int Add(int a, int b);
int Factorial(int n);

int main()
{
	int data = Add(10, 20);

	// 반복문
	// continue: 이번 차례 생략
	// break: 반복문 종료
	 
	// for문
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 1)
		{
			continue;
		}

		printf("Output Test(%d)\n", i);
	}

	// while문
	int i = 0;

	while (i < 10)
	{
		printf("Output Test(%d)\n", i);

		++i;
	}

	scanf_s("%d", &i);
	printf("%d\n", i);

	// 함수가 사용하는 메모리 영역: 스택 메모리 영역(매개변수, 지역변수)

	// Factorial 구현하기
	printf("%d", Factorial(6));
}

int Add(int a, int b)
{
	return a + b;
}

int Factorial(int n)
{
	int value = 1;

	for (int i = n; i > 1; --i)
	{
		value *= i;
	}

	return value;
}
