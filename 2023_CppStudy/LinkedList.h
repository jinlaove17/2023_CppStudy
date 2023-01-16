#pragma once

#include <cassert>

template<typename T>
class CLinkedListIterator;

template<typename T>
class CNode
{
	template<typename T>
	friend class CLinkedList;

	template<typename T>
	friend class CLinkedListIterator;

private:
	T      m_data;

	CNode* m_prev;
	CNode* m_next;

private:
	CNode() :
		m_data(),
		m_prev(nullptr),
		m_next(nullptr)
	{

	}
};

template<typename T>
class CLinkedList
{
public:
	using iterator = CLinkedListIterator<T>;

	template<typename T>
	friend class CLinkedListIterator;

private:
	int          m_size;

	CNode<T>*    m_begin;
	CNode<T>*    m_end;

public:
	CLinkedList() :
		m_size(0),
		m_begin(new CNode<T>),
		m_end(new CNode<T>)
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

	int size()
	{
		return m_size;
	}

	iterator begin()
	{
		return iterator(this, m_begin->m_next);
	}

	iterator end()
	{
		return iterator(this, m_end);
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

	iterator insert(const iterator& iter, const T& data)
	{
		assert(end() != iter);

		CNode<T>* newNode = new CNode<T>;

		newNode->m_data = data;

		// iter 반복자 한 칸 앞에 data를 가진 노드를 삽입한다.

		// iter가 이미 맨 앞 노드인 경우
		if (iter.m_node == m_begin->m_next)
		{
			m_begin->m_next = newNode;
			newNode->m_prev = m_begin;
			newNode->m_next = iter.m_node;
			iter.m_node->m_prev = newNode;
		}
		else
		{
			iter.m_node->m_prev->m_next = newNode;
			newNode->m_prev = iter.m_node->m_prev;
			newNode->m_next = iter.m_node;
			iter.m_node->m_prev = newNode;
		}

		++m_size;

		return iterator(this, newNode);
	}

	iterator erase(iterator& iter)
	{
		assert(end() != iter);

		CNode<T>* deletedNode = iter.m_node;

		deletedNode->m_prev->m_next = deletedNode->m_next;
		deletedNode->m_next->m_prev = deletedNode->m_prev;

		CNode<T>* nextNode = deletedNode->m_next;

		delete deletedNode;

		iter.m_isValid = false;
		--m_size;

		return iterator(this, nextNode);
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

template<typename T>
class CLinkedListIterator
{
	template<typename T>
	friend class CLinkedList;

private:
	CLinkedList<T>* m_linkedList;
	CNode<T>*       m_node;

	bool			m_isValid;

public:
	CLinkedListIterator(CLinkedList<T>* linkedList, CNode<T>* node) :
		m_linkedList(linkedList),
		m_node(node)
	{
		if (nullptr != linkedList && nullptr != node)
		{
			m_isValid = true;
		}
	}

	T& operator *()
	{
		return m_node->m_data;
	}

	bool operator ==(const CLinkedListIterator<T>& other)
	{
		return (m_linkedList == other.m_linkedList) && (m_node == other.m_node);
	}

	bool operator !=(const CLinkedListIterator<T>& other)
	{
		return !(*this == other);
	}

	CLinkedListIterator<T>& operator ++()
	{
		assert(m_node != m_linkedList->m_end && m_isValid);

		m_node = m_node->m_next;

		return *this;
	}

	CLinkedListIterator<T> operator ++(int)
	{
		CLinkedListIterator<T> iter(*this);

		++(*this);

		return iter;
	}

	CLinkedListIterator<T>& operator --()
	{
		assert(m_node != m_linkedList->m_begin && m_isValid);

		m_node = m_node->m_prev;

		return *this;
	}

	CLinkedListIterator<T> operator --(int)
	{
		CLinkedListIterator<T> iter(*this);

		--(*this);

		return iter;
	}
};
