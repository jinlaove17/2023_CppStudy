#include <stdio.h>

// 파일 분리: 가독성 및 유지 보수 향상
#include "func.h"

int main()
{
	int n = Add(1, 5);

	printf("%d\n", n);
}
