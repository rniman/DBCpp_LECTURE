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

	//���� ������ ����
	//MyString(const MyString& source) = delete;

	//������ �ּҰ��� �����ؿ�(����Ʈ ���� ������) -> ���� ����
	//������ �ּҰ��� �����Ҵ�ް� ������������ -> ���� ����
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

	//���� ������
	MyString& operator = (const MyString& source)
	{
		//shallow copy
		//this->m_data = souce.m_data;
		//this->m_length = souce.m_length;
		
		cout << "Assignment operator" << endl;

		//���Կ����ڴ� �ڱⰡ �ڱ⸦ �����ع����� ����
		//self-assignment
		if (this == &source)
			return *this;

		//�̹� �޸𸮸� �����ϰ� ���� �� �ֱ⶧���� delete�� ������
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
		//���� ������ ȣ�� -> ����Ʈ ���� �����ڸ� ����� -> ���� �ּҸ� ������
		MyString copy = hello;
		
		MyString assignment;
		//���� ������ ȣ��
		assignment = copy;
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
		cout << (int*)assignment.m_data << endl;
		cout << assignment.getString() << endl;
		//�������� �����鼭 delete�� ���ѹ���
	}

	//�ּҾȿ� ������ delete�Ǿ����
	cout << hello.getString() << endl;
}