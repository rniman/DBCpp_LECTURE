#include <iostream>
#include <array>
#include <tuple>

using namespace std;

std::tuple<int, double, int> getTuple()
{
	int a = 10;
	double d = 3.14;
	int e = 15;
	return std::make_tuple(a, d, e);
}

int main()
{
	std::tuple<int, double, int> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl;
	cout << std::get<1>(my_tp) << endl;;
	cout << std::get<2>(my_tp) << endl;;


	return 0;
}