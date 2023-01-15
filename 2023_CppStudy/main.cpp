#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> v;
	int size = v.size();
	int capacity = v.capacity();

	v.reserve(3);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[0] *= 1.5;

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	cout << endl;

	list<int> l;

	l.push_back(10);
	l.push_front(20);
	l.push_back(30);

	// �ݺ���(iterator)
	list<int>::iterator iter = l.begin();

	for (; iter != l.end(); ++iter)
	{
		// �ݺ��� ���Ͽ��� operator *�� �����ε� �Ǿ��ִ�.
		// �� �����ڸ� ���� ���� ���� ������ �� �ִ�.
		cout << *iter << endl;
	}
	cout << endl;
}
