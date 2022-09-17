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
	//자식class가 무엇인지 모를경우가 많기에 base를 지워줌 -> ~Base()만 호출되어버림
	//소멸자를 virtual로 만들어줌
	delete base;

	return 0;
}