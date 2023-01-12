#include <stdio.h>

int main()
{
	// void 포인터: 가리키는 곳을 어떤 자료형으로 해석할 지 결정하지 않은 포인터
	void* p = nullptr;

	int a = 0;
	float b = 0.0f;
	double c = 0.0;
	long long d = 0;

	// 어떤 데이터 타입이던 주소를 받을 수 있다.
	p = &a;
	p = &b;
	p = &c;
	p = &d;

	// 역참조, 포인터 연산을 수행할 수 없다.
	// *p;
	// ++p;
}
