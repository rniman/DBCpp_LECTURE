#include <iostream>

using namespace std;

void second();
void third();
void last();

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

void second()
{
	cout << "second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught int exception" << endl;
	}

	cout << "End second" << endl;
}

void third()
{
	cout << "third" << endl;

	last();

	cout << "End third" << endl;
}

void last() throw(int) //exception specifier -> int를 throw할 수 있다// 비우면 예외처리를 안한다는 의미이므로 오류가 남
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;
	throw - 1;
	cout << "End last" << endl;
}

int main()
{
	cout << "start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		//cout cerr clog 
		//기능상 차이는 거의없음 
		//cout 버퍼에 넣음
		//cerr 버퍼에 넣지않음
		cerr << "main caught int exception" << endl;
	}
	//uncaught exception
	catch (...)//catch-all -> 모든형을 받음
	{
		cerr << "Caught any" << endl;
	}

	cout << "End main" << endl;

	return 0;
}