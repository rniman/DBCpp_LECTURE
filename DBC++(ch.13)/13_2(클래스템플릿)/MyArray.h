#pragma once
#include <assert.h>
#include <iostream>

//T_size는 변수가 들어올수 없다 ->(13_3강의)
//compile 타임에 알수있어야하기때문
template<typename T,unsigned int T_size>
class MyArray
{
private:
	//int m_length; -> T_size로 없어도됨
	T* m_data;

public:
	MyArray()
	{
		m_data = new T[T_size];
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength()
	{
		return m_length;
	}

	void print();

};


//MyArray.cpp로 옮겼을때
//main에서는 MyArray에서 어떻게 처리할지를 알수가 없음
//explicit instantiation

//template<typename T>
//void MyArray<T>::print()
//{
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}
