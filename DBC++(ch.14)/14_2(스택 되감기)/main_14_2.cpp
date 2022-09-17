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

void last() throw(int) //exception specifier -> int�� throw�� �� �ִ�// ���� ����ó���� ���Ѵٴ� �ǹ��̹Ƿ� ������ ��
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
		//��ɻ� ���̴� ���Ǿ��� 
		//cout ���ۿ� ����
		//cerr ���ۿ� ��������
		cerr << "main caught int exception" << endl;
	}
	//uncaught exception
	catch (...)//catch-all -> ������� ����
	{
		cerr << "Caught any" << endl;
	}

	cout << "End main" << endl;

	return 0;
}