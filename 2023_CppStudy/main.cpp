#include <stdio.h>

void Test1(int a);
void Test2(int* a);

int main()
{
	int i = 0;

	// 포인터 변수: 주소를 저장하는 변수로 *앞의 자료형으로 해석한다.
	int* p = &i;

	// 포인터 역참조
	*p = 1;

	// 주소는 바이트(byte) 단위로 존재한다.
	// 포인터가 int*, float* 등의 자료형으로 나뉘는 이유는 해당 주소를 쫓아가서 각각 int, float의 크기 만큼을 읽겠다는 것을 뜻한다.
	// 또한 정수와 실수 등 표현 방식이 다르기 때문에 타입별로 포인터를 나눈다.

	// 아래와 같이 강제로 캐스팅하여 int*에 float의 주소를 넣는 경우 실수 표현 방식으로 표현된 곳을 정수 표현 방식으로 4바이트만큼 읽어들여 이상한 값이 나올 것이다.
	// 위 문제는 앞서 배운 것처럼 unsigned char형 변수에 -1을 넣는 경우(-1은 2진법으로 1111 1111이다.) 255로 변하는 것과 같이 자료형에 따라 해석하는 것과 유사하다.
	float f = 3.14f;

	// int*(정수 표현 방식)에 float 주소를 강제 캐스팅
	p = (int*)&f;

	// 3.14f를 정수 표현 방식으로 4바이트만큼 해석한 값이 출력될 것이다.
	printf("%d\n", *p);

	// 32비트(x86) 환경에서는 포인터가 가질 수 있는 주소 번지가 0 ~ UINT_MAX이기 때문에 4GB 이상의 RAM을 사용하더라도 의미가 없다.(포인터의 크기 4Byte)
	// 이와 달리 64비트 환경에서는 32비트 환경보다 더 많은 주소 번지를 가질 수 있다.(포인터의 크기 8Byte)

	int k = 0;

	p = &k;

	// 포인터 변수에 대한 증감 연산은 일반적인 연산과는 다르다.
	// 예를들어, int*를 1 증가시킬 경우, int 자료형의 크기(4)만큼씩 증가한다.
	++p;

	// 포인터와 배열
	// - 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; ++i)
	{
		// int 포인터이기 때문에 +1을 할 때마다 4Byte씩 증가한 위치로 이동한다.
		printf("%d ", *(arr + i)); // arr[i]
	}
	printf("\n");

	// 포인터 이해 확인 문제
	// 문제 1.
	short arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* u = (int*)&arr1;
	int data = *((short*)(u + 2));

	printf("1번 문제 정답: %d\n", data);

	// 문제 2.
	char arr2[2] = { 1, 1 };
	short* s = (short*)arr2;

	data = *s;

	printf("2번 문제 정답: %d\n", data);

	// 문제 3.
	int a = 100;

	Test1(a);

	printf("3번 문제 정답: %d\n", a);

	// 문제 4.
	Test2(&a);

	printf("4번 문제 정답: %d\n", a);
}

void Test1(int a)
{
	a = 500;
}

void Test2(int* a)
{
	*a = 500;
}
