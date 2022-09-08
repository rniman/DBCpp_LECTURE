#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() override
	{
		cout << "Derived1" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_s = "AAA";

	virtual void print() override
	{
		cout << "Derived2" << endl;
	}
};

int main()
{
	Derived1 d1;
	Base* base = &d1;

	d1.m_j;

	auto* base_to_d1 = dynamic_cast<Derived1*>(base);
	cout << base_to_d1->m_j << endl;

	//auto* base_to_d1 = dynamic_cast<Derived2*>(base);  ->nullptr을 넣음
	//static_cast는 가능한 할때까지 함
	return 0;
}