//11_4 
#include <iostream>

class Mother
{
public:
	int m_i;

	Mother()
		:m_i(1)
	{
		std::cout << "Mother Constructor" << std::endl;
	}
};


class  Child : public Mother
{
private:
	double m_d;

public:
	Child()
		:m_d(1.0)
	{
		std:: cout << "Child Constructor" << std::endl;
	}

};

class A
{
public:
	A(int a)
	{
		std::cout << "A Constructor " << a << std::endl;
	}

	~A()
	{
		std::cout << "A destructor " << std::endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a)
	{
		std::cout << "B Constructor " << b << std::endl;
	}

	~B()
	{
		std::cout << "B destructor " << std::endl;
	}
};

class C : public B
{
public:
	C(int a, double b,char c)
		:B(a,b)
	{
		std::cout << "C Constructor " << c << std::endl;
	}

	~C()
	{
		std::cout << "C destructor " << std::endl;
	}
};


int main()
{
	Child child;
	C c(0, 1.0, 'a');

	//padding -> 크기가 달라짐
	std::cout << sizeof(Mother) << std::endl;
	std::cout << sizeof(Child) << std::endl;

	return 0;
}
