#include <iostream>
#include <vector>
#include <array>
#include <cassert>
using namespace std;

class MyString
{

public:
	char* m_data = nullptr;
	int   m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	//복사 생성을 막음
	//MyString(const MyString& source) = delete;

	//포인터 주소값도 복사해옴(디폴트 복사 생성자) -> 얕은 복사
	//포인터 주소값을 새로할당받고 복사하지않음 -> 깊은 복사
	MyString(const MyString& source)
	{
		cout << "copy constructor" << endl;
		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
	}

	~MyString()
	{
		delete[] m_data;
	}

	//대입 연산자
	MyString& operator = (const MyString& source)
	{
		//shallow copy
		//this->m_data = souce.m_data;
		//this->m_length = souce.m_length;
		
		cout << "Assignment operator" << endl;

		//대입연산자는 자기가 자기를 대입해버릴수 있음
		//self-assignment
		if (this == &source)
			return *this;

		//이미 메모리를 차지하고 있을 수 있기때문에 delete를 시켜줌
		delete[] m_data;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}

	char* getString()
	{
		return m_data;
	}
	
	int getLenght()
	{
		return m_length;
	}
};


int main()
{
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		//복사 생성자 호출 -> 디폴트 복사 생성자를 사용함 -> 같은 주소를 가져옴
		MyString copy = hello;
		
		MyString assignment;
		//대입 연산자 호출
		assignment = copy;
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
		cout << (int*)assignment.m_data << endl;
		cout << assignment.getString() << endl;
		//스코프를 나오면서 delete를 시켜버림
	}

	//주소안에 내용이 delete되어버림
	cout << hello.getString() << endl;
}