#pragma once
#include <assert.h>
#include <iostream>

//T_size�� ������ ���ü� ���� ->(13_3����)
//compile Ÿ�ӿ� �˼��־���ϱ⶧��
template<typename T,unsigned int T_size>
class MyArray
{
private:
	//int m_length; -> T_size�� �����
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


//MyArray.cpp�� �Ű�����
//main������ MyArray���� ��� ó�������� �˼��� ����
//explicit instantiation

//template<typename T>
//void MyArray<T>::print()
//{
//	for (int i = 0; i < m_length; ++i)
//		std::cout << m_data[i] << " ";
//	std::cout << std::endl;
//}
