#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main()
{
	// <가변 배열>
	int n = 0;
	
	// 아래 구문은 컴파일 단계에서 지역(함수 내의)의 메모리 크기를 알 수 없기 때문에 불가능하다.
	// int arr[n] = {};

	// 결론적으로 가변 배열을 구현하기 위해서는 힙 영역을 이용해야 한다.

	// <객체(instance)>
	// int a; -- 이 구문에서 int는 자료형, a는 객체(인스턴스)라고 한다.
	
	CDynamicArray<int> dynamicArray;

	for (int i = 0; i < 100; ++i)
	{
		dynamicArray.push_back(i + 1);

		cout << dynamicArray[i] << ' ';
	}

	cout << "\nsize: " << dynamicArray.size() << "\ncapacity: " << dynamicArray.capacity() << '\n';
}
