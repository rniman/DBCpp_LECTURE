#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

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

class CustomVector
{
public:
	unsigned n_data = 0;
	int* ptr = nullptr;

	CustomVector(const unsigned& _n_data, const int& _init = 0)
	{
		cout << "Constructor" << endl;

		init(_n_data, _init);
	}

	CustomVector(CustomVector& l_input)
	{
		cout << "Copy Constructor" << endl;
		init(l_input.n_data);

		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = l_input.ptr[i];
	}

	CustomVector(CustomVector&& r_input)
	{
		cout << "Move Constructor" << endl;

		n_data = r_input.n_data;
		ptr = r_input.ptr;

		r_input.n_data = 0;
		r_input.ptr = nullptr;
	}

	~CustomVector()
	{
		delete[] ptr;
	}

	void init(const unsigned& _n_data, const int& _init = 0)
	{
		n_data = _n_data;
		ptr = new int[n_data];
		for (unsigned i = 0; i < n_data; ++i)
			ptr[i] = _init;
	}
};

void doSomething(CustomVector& vec)
{
	cout << "Pass by L-ref" << endl;
	CustomVector new_vec(vec);
}

void doSomething(CustomVector&& vec)
{
	cout << "Pass by R-ref" << endl;
	//move를 쓰지 않으면 l-value로 받음
	CustomVector new_vec(std::move(vec));
}

//copy와 move를 사용할때 문제가 생김
//r-value를 받지 않고 l-value를 받게됨
//template<typename T>
//void doSomethingTemplate(T  vec)
//{
//	doSomething(vec);
//}

//l-value를 받지 않고 r-value를 받게됨
//template<typename T>
//void doSomethingTemplate(T&& vec)
//{
//	doSomething(std::move(vec));
//}

//foward사용
template<typename T>
void doSomethingTemplate(T&& vec)
{
	doSomething(std::forward<T>(vec));
}

int main()
{
	MyStruct s;
	
	func(s);
	func(MyStruct());

	func_wrapper(s);
	func_wrapper(MyStruct());


	cout << endl;
	cout << endl;

	CustomVector my_vec(10, 1024);
	CustomVector temp(my_vec);

	cout << my_vec.ptr << endl;

	CustomVector temp_move(std::move(my_vec));

	cout << my_vec.ptr << endl;
	cout << temp_move.ptr << endl;

	cout << endl;

	CustomVector my_vec2(10, 1024);
	doSomething(my_vec2);

	//이후 코드에서 my_vec2를 절대로 쓰지않을 것임 -> 이것을 기억해야하므로 권장하지는 않음
	//doSomething(std::move(my_vec2)); 
	doSomething(CustomVector(10, 8));

	cout << endl;

	CustomVector my_vec3(10, 1024);
	doSomethingTemplate(my_vec3);
	doSomethingTemplate(CustomVector(10,8));

	return 0;
}