#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value = 0)
		:m_i(value)
	{}

	void print()
	{
		cout << "BASE" << endl;
	}


};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value = 0)
		:Base(value)
	{}

	//protected���� m_i�� public���� �ٲ����
	using Base::m_i;
private:
	//Base::print()�� private�� �ٲ���� ()���� �ȵ�
	using Base::print;
	//delete�� ��Ű�� �ڽĿ��� ���� �Ұ�
	void print() = delete;

};



int main()
{
	Base base(5);
	base.print();


	Derived derived(7);
	//��밡������
	derived.m_i = 100;
	derived.print();
}