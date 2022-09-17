//1.메모리 누수 발생할수있음
//2.소멸자에서는 예외처리를 할수없다
//3.모든 오류를 예외처리로 잡으려 하지말자

#include <iostream>
#include <memory>//스마트포인터

using namespace std;


class A
{
public:
	//~A()
	//{
	//	//소멸자에서는 예외처리가 금지되어있음
	//	throw "error";
	//}
};

int main()
{

	//메모리누수
	try
	{
		int *i = new int[1000000];
		
		//유니크 포인터 사용하면 delet가 필요없어짐
		//throw시에도 알아서 delete시켜줌
		unique_ptr<int> up_i(i);

		throw "error";

		delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	try
	{
		A a;
	}
	catch (...)
	{
		cout << "A Catch" << endl;
	}

}