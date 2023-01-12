#include <stdio.h>

// 함수 선언 보기 단축키: Ctrl + Shift + Space

// 매개변수로 포인터를 사용하는 경우는, 구조체와 같이 용량이 큰 변수가 복사가 일어나지 않도록 하기 위해서다.
// 64비트 기준 포인터는 8바이트이므로, char, int와 같은 자료형은 복사되는 편이 더 낫다.
void Function(const int* p);

int main()
{
	// 1. const
	const int i = 100;

	// const와 포인터
	int a = 0;
	int* p = &a;

	*p = 1;
	p = nullptr;

	// 2. const 포인터: 포인터가 가리키는 대상의 값을 수정할 수 없게 한다.
	const int* constP = &a; // int const* constP = &a;

	// 가리키는 대상의 값 수정 불가능
	// *constP = 10;

	int b = 0;

	// 다른 대상을 가리키는 것은 가능
	constP = &b;

	// 3. 포인터 const: 포인터가 가리키는 대상을 수정할 수 없게 한다.
	int* const pConst = &a;

	// 가리키는 대상의 값 수정 가능
	*pConst = 10;

	// 다른 대상을 가리키는 것은 불가능
	// pConst = &b;

	// 4. 2, 3번의 경우를 조합
	const int* const constPConst = nullptr;

	{
		int c = 0;
		const int* p = &c;
		
		// 위 코드로 c 자체가 상수화 되는 것이 아니다.
		c = 100;
		
		// 이것은 불가능
		// *p = 100;
	}

	Function(&a);
}

void Function(const int* p)
{
	// const int*를 매개변수를 보냈음에도 수정할 수 있다.
	// 즉, const는 값을 바꾸지 말라는 의도를 내포하는 하나의 약속같은 것이다.
	int* p2 = (int*)p;

	*p2 = 1000;
}
