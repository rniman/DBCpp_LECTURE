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

		//ArrayException으로 던졌지만 Exception으로 받고있음
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
	//catch (ArrayException& exception) //상속받은 예외처리 클래스 -> 객체 잘림 현상발생-> 순서를 바꿔야됨
	//{
	//	cout << "doSomething" << endl;
	//	exception.report();
	//	//rethrow -> 메인에서 예외처리를 한번더 하게됨
	//	throw exception;
	//}
	catch (Exception& exception)
	{
		cout << "doSomething" << endl;
		exception.report();
		//throw exception; -> 객체잘림이 발생하여 main에서는 Exception으로 처리함 
		//throw;를 사용
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