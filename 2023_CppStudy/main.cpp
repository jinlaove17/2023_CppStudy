#include <stdio.h>

// 파일 분리: 가독성 및 유지 보수 향상
#include "func.h"
#include "common.h"

// 전역 변수(global)
int n;

// 정적 변수(static): 전역 변수와 유사하나, 오히려 접근을 파일, 함수, 클래스 등으로 제한함으로써 유지보수나 안정성을 올릴 수 있다.
static int m;

// 외부 변수(extern): common.h에 선언되어 있으며, 최초로 초기화가 필요하다.
int externValue = 0;

int Test()
{
	static int i = 0;

	return ++i;
}

int main()
{
	Test();
	Test();

	int callCount = Test();

	printf("Test() 함수 호출 횟수: %d\n", callCount);

	// * 헤더 파일에 정의된 정적 변수를 각 파일에서 사용하는 예시
	staticValue = 100;

	// F12: 정의로 이동 -> 또 누를시, 선언으로 이동
	int j = Add(10, 20);

	printf("staticValue: %d\n", staticValue);

	// * 헤더 파일에 정의된 외부 변수를 각 파일에서 사용하는 예시
	externValue = 200;

	int k = Sub(20, 10);

	printf("externValue: %d\n", externValue);
}
