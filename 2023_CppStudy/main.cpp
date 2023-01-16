#include <iostream>

#include "LinkedList.h"

using namespace std;

int main()
{
	CLinkedList<int> linkedList;

	linkedList.push_back(10);
	linkedList.push_back(20);
	linkedList.push_back(30);

	CLinkedList<int>::iterator iter = linkedList.begin();

	linkedList.insert(++iter, 15);
	iter = linkedList.insert(linkedList.begin(), 5);

	linkedList.erase(++linkedList.begin());

	cout << linkedList.size() << endl;

	for (; iter != linkedList.end(); ++iter)
	{
		cout << *iter << ' ';
	}
	cout << endl;
}
