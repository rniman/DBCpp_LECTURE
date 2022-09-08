#include <iostream>

using namespace std;

class A
{
private:
	int m_x;
public:
	A(int x) :m_x(x)
	{
		if (x <= 0)
			throw 1;
	}

};

class B : public A
{
public:
	//B(int x)
	//	:A(x)
	//{
	//}

	//function try
	B(int x) try
		:A(x)
	{

	}
	catch (...)
	{
		cout << "Fuction Caught" << endl;
		//throw; -> 있는것 처럼 작동함
	}
};


void doSomething()
{
	try
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Caught any" << endl;
	}

}

int main()
{
	try
	{
		doSomething();
	}
	catch (...)
	{
		cout << "Main Caught" << endl;
	}

	try
	{
		B(0);
	}
	catch (...)
	{
		cout << "Main Caught" << endl;
	}
}