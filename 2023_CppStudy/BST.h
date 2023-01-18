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

	// �ڽ��� ��Ʈ ������� ��ȯ�ϴ� �Լ�
	bool IsRoot()
	{
		return m_nodes[(int)NODE_TYPE::PARENT] == nullptr;
	}

	// �ڽ��� �ܸ� ������� ��ȯ�ϴ� �Լ�
	bool IsLeaf()
	{
		return (m_nodes[(int)NODE_TYPE::LEFT_CHILD] == nullptr) && (m_nodes[(int)NODE_TYPE::RIGHT_CHILD] == nullptr);
	}

	// �ڽ��� ������ �ڽ��� ������ ��ȯ�ϴ� �Լ�
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

	// �ڽ��� �θ��� ���� �ڽ����� ��ȯ�ϴ� �Լ�
	bool IsLeftChild()
	{
		if (IsRoot())
		{
			return false;
		}

		return m_nodes[(int)NODE_TYPE::PARENT]->m_nodes[(int)NODE_TYPE::LEFT_CHILD] == this;
	}

	// �ڽ��� �θ��� ������ �ڽ����� ��ȯ�ϴ� �Լ�
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
	// ��Ʈ ����� �ּ�
	NODE<T1, T2>* m_root;

	// �������� ����
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

		// ù ��° �������� ���
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
					// �ߺ��� ���� �߰��Ϸ��� ��� �ش� ���� �߰����� �ʴ´�.
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
				// �ش� ��带 ã�� ���
				break;
			}

			// �ش� ��带 ã�� ���� ���
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

		// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ���� ������ ��������.
		if (node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
		{
			successor = node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD];

			while (successor->m_nodes[(int)NODE_TYPE::LEFT_CHILD] != nullptr)
			{
				successor = successor->m_nodes[(int)NODE_TYPE::LEFT_CHILD];
			}
		}
		// 2. ������ �ڽ��� ���� ���, successor�� ���� �ڽ��� ������ ���� �ö󰣴�.
		else
		{
			successor = node;

			while (true)
			{
				// ���̻� �������� �ö� �� ����. ===> ������ ��忴��.
				if (successor->IsRoot())
				{
					return nullptr;
				}

				// �θ�κ��� ���� �ڽ����� üũ�Ѵ�.
				if (successor->IsLeftChild())
				{
					// �׶��� �θ� �ļ��ڰ� �ȴ�.
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

		// 1. ���� �ڽ��� �ִ� ���, ���� �ڽ����� ����, ������ �ڽ��� ���� ������ ��������.
		if (node->m_nodes[(int)NODE_TYPE::LEFT_CHILD] != nullptr)
		{
			predecessor = node->m_nodes[(int)NODE_TYPE::LEFT_CHILD];

			while (predecessor->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
			{
				predecessor = predecessor->m_nodes[(int)NODE_TYPE::RIGHT_CHILD];
			}
		}
		// 2. ���� �ڽ��� ���� ���, predecessor�� ������ �ڽ��� ������ ���� �ö󰣴�.
		else
		{
			predecessor = node;

			while (true)
			{
				// ���̻� �������� �ö� �� ����. ===> ������ ��忴��.
				if (predecessor->IsRoot())
				{
					return nullptr;
				}

				// �θ�κ��� ���� �ڽ����� üũ�Ѵ�.
				if (predecessor->IsRightChild())
				{
					// �׶��� �θ� �����ڰ� �ȴ�.
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
		// ������ų ����� �ļ��� ��带 ã�Ƶд�.
		// - GetInOrderPredecessor() �Լ��� �̿��� ������ ��带 ã�Ƶξ �ȴ�.
		NODE<T1, T2>* successor = GetInOrderSuccessor(node);

		// �����Ϸ��� ����� �ڽ� ������ ���� ���� ������ ������.
		switch (node->GetChildCount())
		{
		case 0:
		{
			// 1. ������ų ��尡 ��Ʈ ����� ���
			if (node == m_root)
			{
				m_root = nullptr;
			}
			// 2. ������ų ��尡 ��Ʈ ��尡 �ƴ� ���
			else
			{
				// �θ� ��忡 �����Ͽ�, ������ ���(iter)�� ����Ű�� �����͸� nullptr�� �����.
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
			// ������ų ����� �ļ��� ��带 ã�Ƶд�.
			successor = GetInOrderSuccessor(node);

			NODE_TYPE childType = NODE_TYPE::LEFT_CHILD;

			if (node->m_nodes[(int)NODE_TYPE::RIGHT_CHILD] != nullptr)
			{
				childType = NODE_TYPE::RIGHT_CHILD;
			}

			// 1. ������ų ��尡 ��Ʈ ����� ���
			if (node == m_root)
			{
				node->m_nodes[(int)childType]->m_nodes[(int)NODE_TYPE::PARENT] = nullptr;
				m_root = node->m_nodes[(int)childType];
			}
			// 2. ������ų ��尡 ��Ʈ ��尡 �ƴ� ���
			else
			{
				// ������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
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
			// ������ �ڸ��� ���� �ļ����� ���� �����Ų��.
			node->m_pair = successor->m_pair;

			// ���� �ļ��� ��带 �����Ѵ�.
			DeleteNode(successor);

			// ������ ��尡 ���� �ļ��� ��尡 �ȴ�.
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
	NODE<T1, T2>* m_node; // nullptr�� ���, end iterator�� ���Ѵ�.

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
	
	// first ���� ���Ƿ� �����ϰԵǸ� ���� Ž�� Ʈ���� ���� ����� ��߳��� �ǹǷ� const&�� ��ȯ�Ѵ�.
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
		// ���� ��带 ���� �ļ��ڷ� �����Ѵ�.
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
