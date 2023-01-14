#include <iostream>

#include "DynamicArray.h"

using namespace std;

int main()
{
	// <���� �迭>
	int n = 0;
	
	// �Ʒ� ������ ������ �ܰ迡�� ����(�Լ� ����)�� �޸� ũ�⸦ �� �� ���� ������ �Ұ����ϴ�.
	// int arr[n] = {};

	// ��������� ���� �迭�� �����ϱ� ���ؼ��� �� ������ �̿��ؾ� �Ѵ�.

	// <��ü(instance)>
	// int a; -- �� �������� int�� �ڷ���, a�� ��ü(�ν��Ͻ�)��� �Ѵ�.
	
	CDynamicArray<int> dynamicArray;

	for (int i = 0; i < 100; ++i)
	{
		dynamicArray.push_back(i + 1);

		cout << dynamicArray[i] << ' ';
	}

	cout << "\nsize: " << dynamicArray.size() << "\ncapacity: " << dynamicArray.capacity() << '\n';
}
