#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main()
{
	CDynamicArray<int> dynamicArray;

	dynamicArray.push_back(10);
	dynamicArray.push_back(20);
	dynamicArray.push_back(30);

	for (auto iter = dynamicArray.begin(); iter != dynamicArray.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;

	// 직접 만든 이터레이터를 사용해보자.
	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	cout << *(iter++) << endl;
	cout << *(--iter) << endl;
	cout << *(++iter) << endl;
	cout << *(iter++) << endl;
	cout << *iter << endl;

	// 연산자 우선순위에 의하여 아래 구문은 위와 다른 결과를 출력할 것이다.
	//cout << *(iter++) << ' ' << *(--iter) << ' ' << *(++iter) << ' ' << *(iter++) << ' ' << *iter << endl;
}
