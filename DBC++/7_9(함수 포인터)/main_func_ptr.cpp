#include <iostream>
#include <array>
#include <functional>

using namespace std;

typedef bool(*check_fcn_t)(const int&);

int func()
{ 
	return 5;
}

int goo()
{
	return 10;
}

bool isEven(const int& number)
{
	if (number % 2 == 0)return true;
	else return false;
}

bool isOdd(const int& number)
{
	if (number % 2 != 0)return true;
	else return false;
}

//함수 포인터 이용
void printNum(const array<int, 10>& my_arr, check_fcn_t check_fcn = isOdd)
{

	for (auto elelment : my_arr)
	{
		if (check_fcn(elelment) == true) cout << elelment;
	}
	cout << endl;
}

//일반 함수
void printNum(const array<int, 10>& my_arr, bool print_even)
{

	for (auto elelment : my_arr)
	{
		if (print_even && elelment % 2 == 0 ) cout << elelment;
		if (!print_even && elelment % 2 == 1)cout << elelment;
	}
	cout << endl;
}

int main()
{
	//함수도 주소를 가짐
	cout << func << endl;


	int(*fcn_ptr)() = func;

	cout << fcn_ptr << endl;

	fcn_ptr = goo;

	cout << fcn_ptr << endl;

	std::array<int, 10> my_arr = { 0,1,2,3,4,5,6,7,8,9 };

	printNum(my_arr, 1);
	printNum(my_arr, isEven);
	printNum(my_arr);
	printNum(my_arr, isOdd);

	//functional
	//std::function<bool(const int&)> fcnptr = isEven;
	//printNum(my_arr, fcnptr);

	return 0;
}

