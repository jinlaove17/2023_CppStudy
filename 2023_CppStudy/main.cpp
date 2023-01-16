#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main()
{
	CDynamicArray<int> dynamicArray;

	dynamicArray.push_back(10);
	dynamicArray.push_back(20);
	dynamicArray.push_back(30);

	// 직접 만든 이터레이터를 사용해보자.
	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	dynamicArray.erase(iter);

	// 무효한 반복자 접근 방지 구현
	// int k = *iter;

	for (iter = dynamicArray.begin(); iter != dynamicArray.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;

	//{
	//	// 직접 만든 이터레이터를 사용해보자.
	//	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	//	cout << *(iter++) << endl;
	//	cout << *(--iter) << endl;
	//	cout << *(++iter) << endl;
	//	cout << *(iter++) << endl;
	//	cout << *iter << endl;

	//	// 연산자 우선순위에 의하여 아래 구문은 위와 다른 결과를 출력할 것이다.
	//	//cout << *(iter++) << ' ' << *(--iter) << ' ' << *(++iter) << ' ' << *(iter++) << ' ' << *iter << endl;
	//}

	// erase 사용시 주의할 예시
	dynamicArray.clear();

	// 1 ~ 10으로 채운다.
	for (int i = 0; i < 10; ++i)
	{
		dynamicArray.push_back(i + 1);
	}

	// 짝수만 제거한다.
	for (iter = dynamicArray.begin(); iter != dynamicArray.end();)
	{
		if (0 == *iter % 2)
		{
			iter = dynamicArray.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	for (int i = 0; i < dynamicArray.size(); ++i)
	{
		cout << dynamicArray[i] << ' ';
	}
	cout << "\nsize: " << dynamicArray.size() << endl;
	cout << "capacity: " << dynamicArray.capacity() << endl;
}
