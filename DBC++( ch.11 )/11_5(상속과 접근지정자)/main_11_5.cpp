#include <iostream>
using namespace std;

class Base
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class Derived :/*private*/public Base
{


public:
	Derived()
	{
		m_public = 123;
		m_protected = 123;

		//불가능
		//m_private = 123;
	}

};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived에서 Base를 private로 상속 받으면 이곳에서 받아올 수 없다
		//Derived::m_protected;
	}
};

class Another : protected Base
{
public:
	Another()
	{

	}
};

int main()
{
	Base base;
	Derived derived;
	Another another;

	base.m_public = 123;
	//불가능
	//base.m_protected = 123;
	//base.m_private = 123;

	derived.m_public = 1024;
	//불가능
	//derived.m_protected = 1024;
	//derived.private = 1024;

	//불가능
	another.m_public = 1024;
	return 0;

}