#include <stdio.h>

struct TEST
{
	// 멤버
	int   i;
	float f;
};

int main()
{
	// 구조체와 포인터
	TEST t = { 10, 3.14f };
	TEST* p = &t;

	(*p).i = 100; // p->i = 100;
	(*p).f = 1.414f; // p->f = 1.414f;

	++p; // sizeof(TEST) 바이트만큼 이동한 주소를 가리킨다.
}
