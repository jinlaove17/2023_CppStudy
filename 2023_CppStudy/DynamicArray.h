#pragma once

#include <iostream>
#include <cassert>

template<typename T>
class CDynamicArrayIterator;

template<typename T>
class CDynamicArray
{
public:
	using iterator = CDynamicArrayIterator<T>;

	template<typename T>
	friend class CDynamicArrayIterator;

private:
	T*           m_data;
	unsigned int m_capacity;
	unsigned int m_size;

public:
	CDynamicArray() :
		m_data(nullptr),
		m_capacity(0),
		m_size(0)
	{
	}

	CDynamicArray(unsigned int size) :
		m_data(new T[size]{}),
		m_capacity(size),
		m_size(size)
	{
	}

	~CDynamicArray()
	{
		if (nullptr != m_data)
		{
			delete[] m_data;
		}

		m_capacity = 0;
		m_size = 0;
	}

	T& operator[](int i)
	{
		assert(0 <= i && i < m_size);

		return m_data[i];
	}

	unsigned int size()
	{
		return m_size;
	}

	unsigned int capacity()
	{
		return m_capacity;
	}

	iterator begin()
	{
		if (0 == m_size)
		{
			return end();
		}

		return iterator(this, m_data, 0);
	}

	iterator end()
	{
		// �ε����� -1�� ��츦 end()��� ���Ѵ�.
		return iterator(this, m_data, -1);
	}

	void reserve(unsigned int capacity)
	{
		if (capacity > m_capacity)
		{
			if (nullptr == m_data)
			{
				m_data = new T[capacity]{};
				m_capacity = capacity;
				m_size = 0;
			}
			else
			{
				T* data = new T[capacity]{};

				for (int i = 0; i < m_size; ++i)
				{
					data[i] = m_data[i];
				}

				delete[] m_data;

				m_data = data;
				m_capacity = capacity;
			}
		}
	}

	void push_back(const T& data)
	{
		if (m_size >= m_capacity)
		{
			reserve(2 * (m_capacity + 5));
		}

		m_data[m_size++] = data;
	}
};

template<typename T>
class CDynamicArrayIterator
{
	template<typename T>
	friend class CDynamicArray;

private:
	CDynamicArray<T>* m_dynamicArray;

	// m_dynamicArray�� ��� ������ m_data�� ����Ų��.
	// �� ���� �����ϴ� ������ m_dynamicArray���� �� ������ ���Ҵ��� �ÿ� m_data�� ���� �ּҰ� ����� ���ε� �� ����
	// �� Ŭ����(�ݺ���)�� ������ �ִ� m_data�� ������ ��, �ٸ��ٸ� �� �ݺ��ڴ� ���Ҵ� ������ �� ������ ����Ű�� ��ȿ���� ���� ������ �Ǵ��� �� �ִ�.
	T*				  m_data;

	int				  m_index;

public:
	CDynamicArrayIterator(CDynamicArray<T>* dynamicArray, T* data, int index) :
		m_dynamicArray(dynamicArray),
		m_data(data),
		m_index(index)
	{
	}

	T& operator *()
	{
		assert(m_dynamicArray->m_data == m_data && m_index >= 0);

		return m_data[m_index];
	}

	bool operator ==(const CDynamicArrayIterator& other)
	{
		return (m_dynamicArray == other.m_dynamicArray) && (m_data == other.m_data) && (m_index == other.m_index);
	}

	bool operator !=(const CDynamicArrayIterator& other)
	{
		return !(*this == other);
	}

	// ���� ++
	CDynamicArrayIterator<T>& operator ++()
	{
		// ��ȿ�� �ݺ��ڰ� �ƴ� ��� / end �ݺ����� ���
		assert(m_dynamicArray->m_data == m_data && m_index >= 0);

		// �ݺ��ڰ� ������ �����͸� ����Ű�� �ִ� ���
		if (m_index == m_dynamicArray->m_size - 1)
		{
			// end �ݺ��ڰ� �ȴ�.
			m_index = -1;
		}
		else
		{
			++m_index;
		}

		return *this;
	}

	// ���� ++
	CDynamicArrayIterator<T> operator ++(int)
	{
		// �ʱ�ȭ �ÿ� ���� ������ ���� �����ڸ� ȣ���Ų��.
		CDynamicArrayIterator<T> iter = *this;

		++(*this);

		return iter;
	}

	// ���� --
	CDynamicArrayIterator<T>& operator --()
	{
		// ��ȿ�� �ݺ��ڰ� �ƴ� ��� / begin �ݺ����� ���
		assert(m_dynamicArray->m_data == m_data && m_index > 0);

		--m_index;

		return *this;
	}

	// ���� --
	CDynamicArrayIterator<T> operator --(int)
	{
		CDynamicArrayIterator<T> iter = *this;

		--(*this);

		return *this;
	}
};
