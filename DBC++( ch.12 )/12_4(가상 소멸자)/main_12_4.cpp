#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
	{
		m_array = new int[length];
	}

	virtual ~Derived()
	{
		cout << "~Derived" << endl;
		delete[] m_array;
	}

};

int main()
{
	//Derived derived(5);

	Derived* ptr_derived = new Derived(5);
	Base* base = ptr_derived;
	//�ڽ�class�� �������� �𸦰�찡 ���⿡ base�� ������ -> ~Base()�� ȣ��Ǿ����
	//�Ҹ��ڸ� virtual�� �������
	delete base;

	return 0;
}