#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
	// <���� ����Ʈ>
	CLinkedList<int> linkedList;

	for (int i = 0; i < 10; ++i)
	{
		linkedList.push_back(i);
	}

	cout << linkedList.size() << '\n';
}
