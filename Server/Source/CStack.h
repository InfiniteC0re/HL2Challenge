#pragma once
#include "CLog.h"

template <class T>
class CStack
{
public:
	CStack()
	{
		m_pItems = nullptr;
		m_iMaxTop = 0;
		m_iTop = -1;
	}

	~CStack()
	{
		if (m_pItems)
			delete[] m_pItems;
	}

	bool IsCreated() const
	{
		return m_pItems != nullptr;
	}

	void Create(int size)
	{
		if (!m_pItems)
		{
			m_pItems = new T[size];
			m_iMaxTop = size - 1;
			m_iTop = -1;
		}
	}

	T Pop()
	{
		ASSERT(m_iTop != -1);
		return m_pItems[m_iTop--];
	}

	void Push(const T& value)
	{
		ASSERT(m_iTop != m_iMaxTop);
		m_pItems[++m_iTop] = value;
	}

	T& GetAtTop()
	{
		return m_pItems[m_iTop];
	}

	const T& GetAtTop() const
	{
		return m_pItems[m_iTop];
	}

private:
	T* m_pItems;
	int m_iMaxTop;
	int m_iTop;
};
