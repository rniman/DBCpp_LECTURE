#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct MyStruct
{

};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

template<typename T>
void func_wrapper(T&& t)
{
	//t가 들어올때 lvalue면 lvalue를 리턴 rvalue면 rvalue를 리턴해줌
	func(std::forward<T>(t));
}

int main()
{
	MyStruct s;
	
	func(s);
	func(MyStruct());

	func_wrapper(s);
	func_wrapper(MyStruct());

	return 0;
}