#include <iostream>

namespace work1
{
	namespace work11
	{
		//�ȿ� �� ����� ����
	}
	int a = 5;

	void doSomething() 
	{

		a += 3;
	}
}

namespace work2
{
	int a = 5;

	void doSomething()
	{
		a += 5;
	}
}

int main()
{
	using namespace std;

//	work1::a;
	work1::doSomething();

//	work2::a;
	work2::doSomething();

	cout << work1::a << ' ' << work2::a << endl;

	return 0;
}