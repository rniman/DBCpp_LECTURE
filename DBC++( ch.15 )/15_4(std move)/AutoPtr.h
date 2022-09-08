#pragma once

#include <iostream>

template<class T>
class AutoPtr
{
public:
	T* m_ptr = nullptr;

public:
	AutoPtr()
	{
		std::cout << "AutoPtr default constructor  1\n";
	}

	AutoPtr(T* ptr)
		:m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructor\n";
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor\n";

		if (m_ptr != nullptr)delete m_ptr;
	}

	AutoPtr(const AutoPtr& a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		//deep copy
		m_ptr = new T;
		//Resource의 copy operator를 이용할꺼다
		*m_ptr = *a.m_ptr;
	}

	AutoPtr& operator = (const AutoPtr& a)
	{
		std::cout << "AutoPtr copy assignment" << std::endl;

		if (&a == this)
			return *this;

		if (m_ptr != nullptr)delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;
		
		return *this;
	}

	//강제로 copy 금지시키기
	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator = (const AutoPtr& a) = delete;

	AutoPtr(AutoPtr&& a) noexcept
		:m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;

		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator =(AutoPtr&& a) noexcept
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		if (&a == this)
			return *this;

		if (m_ptr != nullptr)delete m_ptr;

		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }


};
