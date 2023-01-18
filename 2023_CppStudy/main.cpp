#include <iostream>
#include <string>
#include <set>
#include <map>

#include "BST.h"

using namespace std;

// enum������ TYPE_1�� ���� ������ ������ �������� enum class�� ������ ��Ȯ�� �������־�� �ϱ� ������ ��� �����ϴ�.
// ��, enum class�� ����ȯ�� ��������� ���־�� �Ѵ�.
// #define�� �޸� ����� ��, Ÿ�� ������ �ν��ϱ� ������ ���Ǽ��鿡�� ����.
enum class MY_TYPE
{
	TYPE_1,       // 0
	TYPE_2,       // 1
	TYPE_3,       // 2
	TYPE_4,       // 3
	TYPE_5 = 100, // 100
	TYPE_6        // 101
};

enum class OTHER_TYPE
{
	TYPE_1
};

struct STU_INFO
{
	int   m_age;
	float m_height;
	float m_weight;

	STU_INFO() :
		m_age(0),
		m_height(0.0f),
		m_weight(0.0f)
	{

	}

	STU_INFO(int age, float height, float weight) :
		m_age(age),
		m_height(height),
		m_weight(weight)
	{

	}
};

int main()
{
	// <���� Ž��>
	// 1. �����͵��� ���ĵǾ� �־�� �Ѵ�.
	// 2. ���ݾ� ����� ���� �ٿ����� ���� ã�Ƴ�����.

	// <���� Ž�� Ʈ��(Binary Search Tree)>
	// 1. ���� Ž���� ���� ��ȵ� Ʈ��
	// 2. ������ �Է�, Ž�� �� O(logN) ȿ��
	// 3. �־��� ���(�������� ġ��ġ�� ���)���� ȿ���� ������ �ʴ´�.
	// - �̸� ���� �ڰ� ������ �����ϴ� ����� �ʿ��ϴ�.(AVL, Red/Black Tree)

	set<int> s;

	s.insert(100);
	s.insert(50);
	s.insert(150);

	map<string, STU_INFO> m;

	m["JongWoo"] = STU_INFO(26, 180.0f, 70.0f);
	m.insert(make_pair("DaHyuk", STU_INFO(26, 172.0f, 65.0f)));
	m.insert({ "MinHyuk", STU_INFO(34, 183.0f, 77.0f) });

	auto iter = m.find("JongWoo1");

	if (iter != m.end())
	{
		cout << iter->first << " �л��� ã�ҽ��ϴ�!" << endl;
	}
	else
	{
		// Ž���� �����ϸ� end �ݺ��ڸ� ��ȯ�Ѵ�.
		cout << "�ش� �л��� ã�� ���߽��ϴ�." << endl;
	}

	// map�� ���� �����غ���.
	CBST<int, int> bst;

	//         100
	//        /   ��
	//       /     ��
	//      /       ��
	//     50       150
	//    /  ��     / ��
	//   25   75  125 175
	bst.insert(make_Pair(100, 0));
	bst.insert(make_Pair(150, 0));
	bst.insert(make_Pair(50, 0));
	bst.insert(make_Pair(25, 0));
	bst.insert(make_Pair(75, 0));
	bst.insert(make_Pair(125, 0));
	bst.insert(make_Pair(175, 0));

	// <enum class>
	int en = (int)MY_TYPE::TYPE_1;

	CBST<int, int>::iterator myIter = bst.find(50);

	if (myIter != bst.end())
	{
		cout << myIter->m_first << "��(��) ã�ҽ��ϴ�!" << endl;
	}
	else
	{
		// Ž���� �����ϸ� end �ݺ��ڸ� ��ȯ�Ѵ�.
		cout << "ã�� ���߽��ϴ�." << endl;
	}

	// myIter = bst.erase(bst.begin());
	myIter = bst.erase(myIter);

	// ��ȸ
	for (myIter = bst.begin(); myIter != bst.end(); ++myIter)
	{
		cout << myIter->m_first << " - " << myIter->m_second << endl;
	}
}
