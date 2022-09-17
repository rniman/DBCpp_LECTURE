#include <iostream>
#include <array>
#include "Storage.h"

using namespace std;

template<typename T>
class A
{
public:

	A()
	{}

	A(const T& a)
	{}


	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}
	
	void test()
	{}

};

//char 구체화 -> test()가 없으므로 사용 불가능
template<>
class A<char>
{
public:
	A()
	{}

	A(const char& a)
	{}

	void doSomething()
	{
		cout << "Char is specilization" << endl;
	}

};

int main()
{
	A<int> a_int(10);
	//A a_int2(100); -> 버전업하면 가능
	A<double> a_double;
	A<char> a_char;


	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	Storage<int> i_storage;

	for (int i = 0; i < 8; ++i)
		i_storage.set(i, i);

	for (int i = 0; i < 8; ++i)
		cout << i_storage.get(i) << endl;
	
	Storage<bool> bool_storage;
	for (int i = 0; i < 8; ++i)
		bool_storage.set(i, i%2);
	
	cout << boolalpha;
	for (int i = 0; i < 8; ++i)
		cout << bool_storage.get(i) << endl;

	return 0;

}