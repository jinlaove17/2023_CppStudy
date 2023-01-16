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

	// ���� ���� ���ͷ����͸� ����غ���.
	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	cout << *(iter++) << endl;
	cout << *(--iter) << endl;
	cout << *(++iter) << endl;
	cout << *(iter++) << endl;
	cout << *iter << endl;

	// ������ �켱������ ���Ͽ� �Ʒ� ������ ���� �ٸ� ����� ����� ���̴�.
	//cout << *(iter++) << ' ' << *(--iter) << ' ' << *(++iter) << ' ' << *(iter++) << ' ' << *iter << endl;
}
