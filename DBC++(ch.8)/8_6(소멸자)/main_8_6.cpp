#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		:m_id(id_in)
	{
		cout << "Constructor" << m_id << endl;
	}

	~Simple()
	{
		cout << "Distructor " << m_id << endl;
	}
};

//소멸자 용도-> 동적할당
class IntArray
{
private:
	int* m_array = nullptr;
	int m_length = 0;

public:
	IntArray(const int length_in)
	{
		m_length = length_in;
		m_array = new int[m_length];

		cout << "Constructor" << endl;

	}

	~IntArray()
	{
		if(m_array != nullptr)
			delete[] m_array;
	}

	int getLength() { return m_length; }

};

int main()
{
	Simple* s3 = new Simple(3);
	Simple s1(0);
	Simple s2(1);

	delete s3;

	while (1)
	{
		//메모리 누수 -> 소멸자 이용
		IntArray my_int_array(10000);


	}

	return 0;
}