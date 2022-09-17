//프로젝트 속성 -> C/C++ -> 언어 -> C++ 언어 표준 (17이상으로 해야됨)

#include <iostream>
#include <tuple>

using namespace std;


//과거 tuple
tuple<int, int> my_func()
{
	return tuple<int, int>(123, 456);
}

//현대 tuple
auto my_func2()
{
	//<int,int>생략가능
	return tuple(123, 456, 789);
}

int main()
{
	tuple<int, int> result = my_func();
	auto result2 = my_func2();
	
	//a b c에 각각 넣어 줌
	auto [a, b, c] = my_func2();

	cout << get<0>(result) << " " << get<1>(result) << endl;
	cout << get<0>(result2) << " " << get<2>(result2) << endl;
	cout << a << " " << b << " " << c;

	return 0;
}