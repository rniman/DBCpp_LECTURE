#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int*	 m_data = nullptr;

public:
	IntArray()
	{

	}

	IntArray(const unsigned& length)
		:m_length(length)
	{
		m_data = new int[length];
	}

	//이니셜라이즈를 파라미터로 받는 생성자
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			m_data[count] = element;
			++count;
			//list[count]->이니셜라이즈 리스트는 대괄호 오퍼레이터를 제공하지 않음
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	IntArray& operator = (const std::initializer_list<int>& arr)
	{
		if (m_data != nullptr && m_length == arr.size())
		{
			int count = 0;
			for (auto& element : arr)
			{
				if (m_data[count] == element)
				{
					count++;
				}
			}
			if (count == m_length) {
				cout << "Self-Assignment" << endl;
				return *this;
			}
		}


		delete[] m_data;

		m_length = arr.size();


		if (arr.begin() != nullptr)
		{
			m_data = new int[m_length];

			unsigned count = 0;
			for (auto& element : arr)
			{
				assert(count < m_length);
				m_data[count] = element;
				count++;
			}
		}
		else
		{
			m_data = nullptr;
		}

		return *this;
	}

	friend ostream& operator << (ostream& out, const IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
		{
			out << arr.m_data[i] << ' ';
		}
		out << endl;
		return out;
	}
};


int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };

	//auto를 잡아줌
	auto il = { 10,20,30 };

	IntArray int_arr{ 1,2,3,4,5 };
	cout << int_arr << endl;
	int_arr = { 1,5,7,8,9,10,15 };
	cout << int_arr << endl;

	IntArray temp;
	temp = { 10,2,5,8 };
	cout << temp << endl;
	cout << "Self-Assignment 시도" << endl;
	temp = { 10,2,5,8 };
	cout << temp << endl;
	return 0;
}