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

	//protected였던 m_i를 public으로 바꿔버림
	using Base::m_i;
private:
	//Base::print()를 private를 바꿔버림 ()쓰면 안됨
	using Base::print;
	//delete를 시키면 자식에선 접근 불가
	void print() = delete;

};



int main()
{
	Base base(5);
	base.print();


	Derived derived(7);
	//사용가능해짐
	derived.m_i = 100;
	derived.print();
}