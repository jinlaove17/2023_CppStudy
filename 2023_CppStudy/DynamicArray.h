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
		// 인덱스가 -1인 경우를 end()라고 정한다.
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

	// m_dynamicArray의 멤버 변수인 m_data를 가리킨다.
	// 이 값을 저장하는 이유는 m_dynamicArray에서 힙 영역을 재할당할 시에 m_data의 시작 주소가 변경될 것인데 이 값과
	// 이 클래스(반복자)가 가지고 있는 m_data를 비교했을 때, 다르다면 이 반복자는 재할당 이전의 힙 영역을 가리키는 유효하지 않은 것으로 판단할 수 있다.
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

	// 전위 ++
	CDynamicArrayIterator<T>& operator ++()
	{
		// 유효한 반복자가 아닌 경우 / end 반복자인 경우
		assert(m_dynamicArray->m_data == m_data && m_index >= 0);

		// 반복자가 마지막 데이터를 가리키고 있는 경우
		if (m_index == m_dynamicArray->m_size - 1)
		{
			// end 반복자가 된다.
			m_index = -1;
		}
		else
		{
			++m_index;
		}

		return *this;
	}

	// 후위 ++
	CDynamicArrayIterator<T> operator ++(int)
	{
		// 초기화 시에 대입 연산은 복사 생성자를 호출시킨다.
		CDynamicArrayIterator<T> iter = *this;

		++(*this);

		return iter;
	}

	// 전위 --
	CDynamicArrayIterator<T>& operator --()
	{
		// 유효한 반복자가 아닌 경우 / begin 반복자인 경우
		assert(m_dynamicArray->m_data == m_data && m_index > 0);

		--m_index;

		return *this;
	}

	// 후위 --
	CDynamicArrayIterator<T> operator --(int)
	{
		CDynamicArrayIterator<T> iter = *this;

		--(*this);

		return *this;
	}
};
