#include <stdio.h>

int main()
{
	// l-value: 변수
	// r-value: 상수

	// const(상수화)
	const int i = 100;

	// 불가능
	// i = 100;
	
	// 강제 캐스팅
	int* p = (int*)&i;

	// 값을 바꿀 수 있다.
	*p = 300;

	printf("%d\n", *p);
}
