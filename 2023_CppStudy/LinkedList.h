#pragma once

template<typename T>
class CNode
{
	template<typename T>
	friend class CLinkedList;

private:
	T      m_data;

	CNode* m_prev;
	CNode* m_next;

private:
	CNode() : m_data(), m_prev(nullptr), m_next(nullptr) {}
};

template<typename T>
class CLinkedList
{
private:
	unsigned int m_size;

	CNode<T>*    m_begin;
	CNode<T>*    m_end;

public:
	CLinkedList() : m_size(0), m_begin(new CNode<T>), m_end(new CNode<T>)
	{
		m_begin->m_next = m_end;
		m_end->m_prev = m_begin;
	}

	~CLinkedList()
	{
		clear();

		delete m_begin;
		delete m_end;
	}

	unsigned int size()
	{
		return m_size;
	}

	void push_front(const T& data)
	{
		CNode<T>* newNode = new CNode<T>;

		newNode->m_data = data;

		CNode<T>* firstNode = m_begin->m_next;

		m_begin->m_next = newNode;
		newNode->m_prev = m_begin;
		newNode->m_next = firstNode;
		firstNode->m_prev = newNode;

		++m_size;
	}

	void push_back(const T& data)
	{
		CNode<T>* newNode = new CNode<T>;

		newNode->m_data = data;

		CNode<T>* lastNode = m_end->m_prev;

		lastNode->m_next = newNode;
		newNode->m_prev = lastNode;
		newNode->m_next = m_end;
		m_end->m_prev = newNode;

		++m_size;
	}

	void clear()
	{
		CNode<T>* node = m_begin->m_next;

		while (node != m_end)
		{
			CNode<T>* next = node->m_next;

			delete node;

			node = next;
		}

		m_size = 0;

		m_begin->m_next = m_end;
		m_end->m_prev = m_begin;
	}
};
