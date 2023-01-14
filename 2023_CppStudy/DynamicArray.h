#pragma once

#include <cassert>

template<typename T>
class CDynamicArray
{
private:
	T*           m_p;
	unsigned int m_capacity;
	unsigned int m_size;

public:
	CDynamicArray() : m_p(nullptr), m_capacity(0), m_size(0)
	{
	}

	CDynamicArray(unsigned int size) : m_p(new T[size]{}), m_capacity(size), m_size(size)
	{
	}

	~CDynamicArray()
	{
		if (nullptr != m_p)
		{
			delete[] m_p;
		}

		m_capacity = 0;
		m_size = 0;
	}

	T& operator[](int i)
	{
		assert(0 <= i && i < m_size);

		return m_p[i];
	}

	unsigned int size()
	{
		return m_size;
	}

	unsigned int capacity()
	{
		return m_capacity;
	}

	void reserve(int capacity)
	{
		if (capacity > m_capacity)
		{
			if (nullptr == m_p)
			{
				m_p = new T[capacity]{};
				m_capacity = capacity;
				m_size = 0;
			}
			else
			{
				T* p = new T[capacity]{};

				for (int i = 0; i < m_size; ++i)
				{
					p[i] = m_p[i];
				}

				delete[] m_p;

				m_p = p;
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

		m_p[m_size++] = data;
	}
};
