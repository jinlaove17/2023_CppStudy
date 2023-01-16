#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main()
{
	CDynamicArray<int> dynamicArray;

	dynamicArray.push_back(10);
	dynamicArray.push_back(20);
	dynamicArray.push_back(30);

	// ���� ���� ���ͷ����͸� ����غ���.
	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	dynamicArray.erase(iter);

	// ��ȿ�� �ݺ��� ���� ���� ����
	// int k = *iter;

	for (iter = dynamicArray.begin(); iter != dynamicArray.end(); iter++)
	{
		cout << *iter << ' ';
	}
	cout << endl;

	//{
	//	// ���� ���� ���ͷ����͸� ����غ���.
	//	CDynamicArray<int>::iterator iter = dynamicArray.begin();

	//	cout << *(iter++) << endl;
	//	cout << *(--iter) << endl;
	//	cout << *(++iter) << endl;
	//	cout << *(iter++) << endl;
	//	cout << *iter << endl;

	//	// ������ �켱������ ���Ͽ� �Ʒ� ������ ���� �ٸ� ����� ����� ���̴�.
	//	//cout << *(iter++) << ' ' << *(--iter) << ' ' << *(++iter) << ' ' << *(iter++) << ' ' << *iter << endl;
	//}

	// erase ���� ������ ����
	dynamicArray.clear();

	// 1 ~ 10���� ä���.
	for (int i = 0; i < 10; ++i)
	{
		dynamicArray.push_back(i + 1);
	}

	// ¦���� �����Ѵ�.
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
