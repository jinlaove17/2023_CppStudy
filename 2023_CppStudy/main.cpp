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

	// 반복자(iterator)
	list<int>::iterator iter = l.begin();

	for (; iter != l.end(); ++iter)
	{
		// 반복자 패턴에는 operator *가 오버로딩 되어있다.
		// 이 연산자를 통해 실제 값에 접근할 수 있다.
		cout << *iter << endl;
	}
	cout << endl;
}
