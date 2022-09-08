#include <iostream>
#include <array>
#include <vector>
#include <initializer_list>

class IntArray
{
private:
	int m_length = 0;
	int* m_data = nullptr;

public:
	//Constructors
	IntArray(const int& length_in)
		:m_length(length_in)
	{
		m_data = new int[m_length];
	}

	//initialize()
	IntArray(const std::initializer_list<int>& list)
		:IntArray(list.size())
	{
		int count = 0;
		for (auto& ele : list)
		{
			m_data[count] = ele;
			count++;
		}

	}

	//Destructors
	~IntArray()
	{
		delete[] m_data;
	}


	//reset()
	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	//resize()
	void resize(const int& resize_in)
	{

		int* temp = new int[resize_in];


		for (unsigned i = 0; i < resize_in; ++i)
		{
			//m_length가 resize_in보다 작을경우
			if (i == m_length)
				break;

			temp[i] = m_data[i];
		}
		delete[] m_data;

		m_length = resize_in;
		m_data = temp;

		temp = nullptr;
	}

	//insertBefore(const int & value,const int& ix)
	void insertBefore(const int& value, const int& ix)
	{
		if (ix == m_length)
		{
			push_back(value);
		}
		else if (ix > m_length)
		{
			std::cout << "할 수 없다!\n";
		}

		resize(m_length + 1);

		for (unsigned i = m_length - 1; i > ix; --i)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[ix] = value;

	}

	//remove(const int & ix)
	void remove(const int& ix)
	{
		for (unsigned i = ix; i < m_length - 1; ++i)
		{
			m_data[i] = m_data[i + 1];
		}

		resize(m_length - 1);
	}
	//push_back(const int& value)
	void push_back(const int& value)
	{
		resize(m_length + 1);
		m_data[m_length - 1] = value;
	}

	//output operator
	friend std::ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << ' ';
		out << std::endl;
		return out;
	}

};

int main()
{


	IntArray my_arr{ 1,3,5,6,8 };
	std::cout << my_arr;

	my_arr.insertBefore(10, 1);
	std::cout << my_arr;

	my_arr.remove(3);
	std::cout << my_arr;

	my_arr.push_back(13);
	std::cout << my_arr;

	my_arr.reset();



	std::vector<int> int_vec;
	std::array<int, 10> int_arr;


}