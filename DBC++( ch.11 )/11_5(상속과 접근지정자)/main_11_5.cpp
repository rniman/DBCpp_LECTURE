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

		//�Ұ���
		//m_private = 123;
	}

};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		//Derived���� Base�� private�� ��� ������ �̰����� �޾ƿ� �� ����
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
	//�Ұ���
	//base.m_protected = 123;
	//base.m_private = 123;

	derived.m_public = 1024;
	//�Ұ���
	//derived.m_protected = 1024;
	//derived.private = 1024;

	//�Ұ���
	another.m_public = 1024;
	return 0;

}