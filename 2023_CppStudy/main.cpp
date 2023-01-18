#include <iostream>
#include <string>
#include <set>
#include <map>

#include "BST.h"

using namespace std;

// enum에서는 TYPE_1에 대한 재정의 오류를 내보지만 enum class는 범위를 명확히 지정해주어야 하기 때문에 사용 가능하다.
// 단, enum class는 형변환을 명시적으로 해주어야 한다.
// #define과 달리 디버깅 시, 타입 정보를 인식하기 때문에 편의성면에서 좋다.
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
	// <이진 탐색>
	// 1. 데이터들이 정렬되어 있어야 한다.
	// 2. 절반씩 경우의 수를 줄여가며 값을 찾아나간다.

	// <이진 탐색 트리(Binary Search Tree)>
	// 1. 이진 탐색을 위해 고안된 트리
	// 2. 데이터 입력, 탐색 시 O(logN) 효율
	// 3. 최악의 경우(한쪽으로 치우치는 경우)에는 효율이 나오지 않는다.
	// - 이를 위해 자가 균형을 유지하는 기능이 필요하다.(AVL, Red/Black Tree)

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
		cout << iter->first << " 학생을 찾았습니다!" << endl;
	}
	else
	{
		// 탐색에 실패하면 end 반복자를 반환한다.
		cout << "해당 학생을 찾지 못했습니다." << endl;
	}

	// map을 직접 구현해보자.
	CBST<int, int> bst;

	//         100
	//        /   ＼
	//       /     ＼
	//      /       ＼
	//     50       150
	//    /  ＼     / ＼
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
		cout << myIter->m_first << "을(를) 찾았습니다!" << endl;
	}
	else
	{
		// 탐색에 실패하면 end 반복자를 반환한다.
		cout << "찾지 못했습니다." << endl;
	}

	// myIter = bst.erase(bst.begin());
	myIter = bst.erase(myIter);

	// 순회
	for (myIter = bst.begin(); myIter != bst.end(); ++myIter)
	{
		cout << myIter->m_first << " - " << myIter->m_second << endl;
	}
}
