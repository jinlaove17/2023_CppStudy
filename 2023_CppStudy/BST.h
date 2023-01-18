#pragma once

#include <cassert>

enum class NODE_TYPE
{
	PARENT,
	LEFT_CHILD,
	RIGHT_CHILD,

	COUNT
};

template<typename T1, typename T2>
struct PAIR
{
public:
	T1 m_first;
	T2 m_second;

public:
	PAIR() :
		m_first(),
		m_second()
	{

	}

	PAIR(T1 first, T2 second) :
		m_first(first),
		m_second(second)
	{

	}
};

template<typename T1, typename T2>
PAIR<T1, T2> make_Pair(const T1& first, const T2& second)
{
	return PAIR<T1, T2>(first, second);
}

template<typename T1, typename T2>
struct NODE
{
public:
	PAIR<T1, T2> m_pair;

	NODE*        m_nodes[(int)NODE_TYPE::COUNT];

public:
	NODE(const PAIR<T1, T2>& pair, NODE* parent, NODE* leftChild, NODE* rightChild) :
		m_pair(pair),
		m_nodes{ parent, leftChild, rightChild }
	{

	}

	// 자신이 루트 노드인지 반환하는 함수
	bool IsRoot()
	{
		return m_nodes[(int)NODE_TYPE::PARENT] == nullptr;
	}

	// 자신이 단말 노드인지 반환하는 함수
	bool IsLeaf()
	{
		return (m_nodes[(int)NODE_TYPE::LEFT_CHILD] == nullptr) && (m_nodes[(int)NODE_TYPE::RIGHT_CHILD] == nullptr);
	}

	// 자신이 보유한 자식의 개수를 반환하는 함수
	int GetChildCount()
	{
		int childCount = 0;

		for (int i = (int)NODE_TYPE::LEFT_CHILD; i < (int)NODE_TYPE::COUNT; ++i)
		{
			if (m_nodes[i] != nullptr)
			{
				++childCount;
			}
		}

		return childCount;
	}

	// 자신이 부모의 왼쪽 자식인지 반환하는 함수
	bool IsLeftChild()
	{
		if (IsRoot())
		{
			return false;
		}

		return m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::LEFT_CHILD] == this;
	}

	// 자신이 부모의 오른쪽 자식인지 반환하는 함수
	bool IsRightChild()
	{
		if (IsRoot())
		{
			return false;
		}

		return m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] == this;
	}
};

template<typename T1, typename T2>
class CBSTIterator;

template<typename T1, typename T2>
class CBST
{
public:
	using iterator = CBSTIterator<T1, T2>;

private:
	// 루트 노드의 주소
	NODE<T1, T2>* m_root;

	// 데이터의 개수
	int			  m_size;

public:
	CBST() :
		m_root(nullptr),
		m_size(0)
	{

	}

	iterator begin()
	{
		NODE<T1, T2>* node = m_root;

		while (node->m_nodes[(int)NODE_TYPE::LEFT_CHILD] != nullptr)
		{
			node = node->m_nodes[(int)NODE_TYPE::LEFT_CHILD];
		}

		return iterator(this, node);
	}

	iterator end()
	{
		return iterator(this, nullptr);
	}

	bool insert(const PAIR<T1, T2>& pair)
	{
		NODE<T1, T2>* newNode = new NODE<T1, T2>(pair, nullptr, nullptr, nullptr);

		// 첫 번째 데이터인 경우
		if (m_root == nullptr)
		{
			m_root = newNode;
		}
		else
		{
			NODE<T1, T2>* node = m_root;
			NODE_TYPE nodeType;

			while (true)
			{
				if (newNode->m_pair.m_first < node->m_pair.m_first)
				{
					nodeType = NODE_TYPE::LEFT_CHILD;
				}
				else if (newNode->m_pair.m_first > node->m_pair.m_first)
				{
					nodeType = NODE_TYPE::RIGHT_CHILD;
				}
				else
				{
					// 중복된 값을 추가하려는 경우 해당 노드는 추가하지 않는다.
					delete newNode;

					return false;
				}

				if (node->m_nodes[(int)nodeType] == nullptr)
				{
					node->m_nodes[(int)nodeType] = newNode;
					newNode->m_nodes[(int)NODE_TYPE::PARENT] = node;

					break;
				}

				node = node->m_nodes[(int)nodeType];
			}
		}

		++m_size;

		return true;
	}

	iterator erase(const iterator& iter)
	{
		assert(this == iter.m_bst && iter.m_node != nullptr);

		NODE<T1, T2>* node = DeleteNode(iter.m_node);

		--m_size;

		return iterator(this, node);
	}

	iterator find(const T1& key)
	{
		NODE<T1, T2>* node = m_root;
		NODE_TYPE nodeType;

		while (true)
		{
			if (key < node->m_pair.m_first)
			{
				nodeType = NODE_TYPE::LEFT_CHILD;
			}
			else if (key > node->m_pair.m_first)
			{
				nodeType = NODE_TYPE::RIGHT_CHILD;
			}
			else
			{
				// 해당 노드를 찾은 경우
				break;
			}

			// 해당 노드를 찾지 못한 경우
			if (nullptr == node->m_nodes[(int)nodeType])
			{
				return iterator(this, nullptr);
			}

			node = node->m_nodes[(int)nodeType];
		}

		return iterator(this, node);
	}

	NODE<T1, T2>* GetInOrderSuccessor(NODE<T1, T2>* node)
	{
		NODE<T1, T2>* successor = nullptr;

		// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을 때까지 내려간다.
		if (node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
		{
			successor = node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD];

			while (successor->m_nodes[(int)NODE_TYPE::LEFT_CHILD] != nullptr)
			{
				successor = successor->m_nodes[(int)NODE_TYPE::LEFT_CHILD];
			}
		}
		// 2. 오른쪽 자식이 없는 경우, successor가 왼쪽 자식일 때까지 위로 올라간다.
		else
		{
			successor = node;

			while (true)
			{
				// 더이상 위쪽으로 올라갈 수 없다. ===> 마지막 노드였다.
				if (successor->IsRoot())
				{
					return nullptr;
				}

				// 부모로부터 왼쪽 자식인지 체크한다.
				if (successor->IsLeftChild())
				{
					// 그때의 부모가 후속자가 된다.
					successor = successor->m_nodes[(int)NODE_TYPE::PARENT];

					break;
				}
				
				successor = successor->m_nodes[(int)NODE_TYPE::PARENT];
			}
		}

		return successor;
	}

	NODE<T1, T2>* GetInOrderPredecessor(NODE<T1, T2>* node)
	{
		NODE<T1, T2>* predecessor = nullptr;

		// 1. 왼쪽 자식이 있는 경우, 왼쪽 자식으로 가서, 오른쪽 자식이 없을 때까지 내려간다.
		if (node->m_nodes[(int)NODE_TYPE::LEFT_CHILD] != nullptr)
		{
			predecessor = node->m_nodes[(int)NODE_TYPE::LEFT_CHILD];

			while (predecessor->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
			{
				predecessor = predecessor->m_nodes[(int)NODE_TYPE::RIGHT_CHILD];
			}
		}
		// 2. 왼쪽 자식이 없는 경우, predecessor가 오른쪽 자식일 때까지 위로 올라간다.
		else
		{
			predecessor = node;

			while (true)
			{
				// 더이상 위쪽으로 올라갈 수 없다. ===> 마지막 노드였다.
				if (predecessor->IsRoot())
				{
					return nullptr;
				}

				// 부모로부터 왼쪽 자식인지 체크한다.
				if (predecessor->IsRightChild())
				{
					// 그때의 부모가 선행자가 된다.
					predecessor = predecessor->m_nodes[(int)NODE_TYPE::PARENT];

					break;
				}

				predecessor = predecessor->m_nodes[(int)NODE_TYPE::PARENT];
			}
		}

		return predecessor;
	}

private:
	NODE<T1, T2>* DeleteNode(NODE<T1, T2>* node)
	{
		// 삭제시킬 노드의 후속자 노드를 찾아둔다.
		// - GetInOrderPredecessor() 함수를 이용해 선행자 노드를 찾아두어도 된다.
		NODE<T1, T2>* successor = GetInOrderSuccessor(node);

		// 삭제하려는 노드의 자식 개수에 따라 삭제 조건이 나뉜다.
		switch (node->GetChildCount())
		{
		case 0:
		{
			// 1. 삭제시킬 노드가 루트 노드인 경우
			if (node == m_root)
			{
				m_root = nullptr;
			}
			// 2. 삭제시킬 노드가 루트 노드가 아닌 경우
			else
			{
				// 부모 노드에 접근하여, 삭제할 노드(iter)를 가리키는 포인터를 nullptr로 만든다.
				if (node->IsLeftChild())
				{
					node->m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::LEFT_CHILD] = nullptr;
				}
				else
				{
					node->m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] = nullptr;
				}
			}

			delete node;
		}
			break;
		case 1:
		{
			// 삭제시킬 노드의 후속자 노드를 찾아둔다.
			successor = GetInOrderSuccessor(node);

			NODE_TYPE childType = NODE_TYPE::LEFT_CHILD;

			if (node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
			{
				childType = NODE_TYPE::RIGHT_CHILD;
			}

			// 1. 삭제시킬 노드가 루트 노드인 경우
			if (node == m_root)
			{
				node->m_nodes[(int)childType]->m_nodes[(int)NODE_TYPE::PARENT] = nullptr;
				m_root = node->m_nodes[(int)childType];
			}
			// 2. 삭제시킬 노드가 루트 노드가 아닌 경우
			else
			{
				// 삭제할 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
				if (node->IsLeftChild())
				{
					node->m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::LEFT_CHILD] = node->m_nodes[(int)childType];
				}
				else
				{
					node->m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] = node->m_nodes[(int)childType];
				}

				node->m_nodes[(int)childType]->m_nodes[(int)NODE_TYPE::PARENT] = node->m_nodes[(int)NODE_TYPE::PARENT];
			}

			delete node;
		}
			break;
		case 2:
		{
			// 삭제될 자리에 중위 후속자의 값을 복사시킨다.
			node->m_pair = successor->m_pair;

			// 중위 후속자 노드를 삭제한다.
			DeleteNode(successor);

			// 삭제할 노드가 중위 후속자 노드가 된다.
			successor = node;
		}
			break;
		}

		return successor;
	}
};

template<typename T1, typename T2>
class CBSTIterator
{
	friend class CBST<T1, T2>;

private:
	CBST<T1, T2>* m_bst;
	NODE<T1, T2>* m_node; // nullptr인 경우, end iterator를 뜻한다.

public:
	CBSTIterator() :
		m_bst(nullptr),
		m_node(nullptr)
	{

	}

	CBSTIterator(CBST<T1, T2>* bst, NODE<T1, T2>* node) :
		m_bst(bst),
		m_node(node)
	{

	}
	
	// first 값을 임의로 수정하게되면 이진 탐색 트리의 보관 방식이 어긋나게 되므로 const&로 반환한다.
	const PAIR<T1, T2>& operator *()
	{
		assert(m_node != nullptr);

		return m_node->m_pair;
	}

	const PAIR<T1, T2>* operator ->()
	{
		assert(m_node != nullptr);

		return &m_node->m_pair;
	}

	CBSTIterator<T1, T2>& operator ++()
	{
		// 현재 노드를 중위 후속자로 변경한다.
		m_node = m_bst->GetInOrderSuccessor(m_node);

		return *this;
	}

	bool operator ==(const CBSTIterator<T1, T2>& other)
	{
		return (m_bst == other.m_bst) && (m_node == other.m_node);
	}

	bool operator !=(const CBSTIterator<T1, T2>& other)
	{
		return !(*this == other);
	}
};
