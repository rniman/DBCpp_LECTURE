#include <iostream>
using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "ArrayException report" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int& operator [](const int& index)
	{
		//if (index < 0 || index >= 5)throw - 1;
		//if (index < 0 || index >= 5)throw Exception();

		//ArrayException���� �������� Exception���� �ް�����
		if (index < 0 || index >= 5)throw ArrayException();

		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cout << "doSomething" << endl;
		cerr << "Exception " << x << endl;
	}
	//catch (Exception& exception)
	//{
	//	exception.report();
	//}
	//catch (ArrayException& exception) //��ӹ��� ����ó�� Ŭ���� -> ��ü �߸� ����߻�-> ������ �ٲ�ߵ�
	//{
	//	cout << "doSomething" << endl;
	//	exception.report();
	//	//rethrow -> ���ο��� ����ó���� �ѹ��� �ϰԵ�
	//	throw exception;
	//}
	catch (Exception& exception)
	{
		cout << "doSomething" << endl;
		exception.report();
		//throw exception; -> ��ü�߸��� �߻��Ͽ� main������ Exception���� ó���� 
		//throw;�� ���
		throw;
	}
}

int main()
{
	//try
	//{
	//	doSomething();
	//}
	//catch (ArrayException& exception)
	//{
	//	cout << "main" << endl;
	//	exception.report();
	//}

	try
	{
		doSomething();
	}
	catch (ArrayException& exception)
	{
		cout << "main" << endl;
		exception.report();
	}
	catch (Exception& exception)
	{
		cout << "main" << endl;
		exception.report();
	}



	return 0;
}