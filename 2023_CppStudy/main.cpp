#include <stdio.h>
#include <stdlib.h>

// <메모리 영역>
// 1. 코드 영역
// 2. 데이터 영역: 전역 변수, 정적 변수(static), 외부 변수(extern)
// 3. 힙 영역: 동적 할당 변수
// 4. 스택 영역: 지역 변수, 매개 변수

int main()
{
	// <동적 할당>
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 메모리를 관리해주어야 한다.

	// malloc(): 힙 영역에 매개변수 만큼의 영역을 할당하고 시작 주소를 void*로 반환한다.
	// 할당된 영역을 어떤 방식으로 해석할지에 따라 포인터의 타입을 정하여 강제 타입캐스팅을 통해 초기화하면 된다.
	int* p1 = (int*)malloc(4);

	// 정수 표현 방식으로 4바이트만큼 해석
	*p1 = 100;

	float* p2 = (float*)p1;

	// 실수 표현 방식으로 4바이트만큼 해석
	*p2 = 3.14f;

	if (nullptr != p1)
	{
		// free(): 할당 된 메모리 반납
		free(p1);
	}

	// new: malloc의 c++ 버전
	int* p3 = new int;

	*p3 = 10;

	printf("%d\n", *p3);

	if (nullptr != p3)
	{
		// delete: free의 c++ 버전
		delete p3;
	}

	// new type[]: 동적 배열 생성
	double* p4 = new double[10] {};

	for (int i = 0; i < 10; ++i)
	{
		p4[i] = 1.0f * i;
		
		printf("%f\n", p4[i]);
	}

	if (nullptr != p4)
	{
		// delete[]: 동적 배열 해제
		delete[] p4;
	}
}
