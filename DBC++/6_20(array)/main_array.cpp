#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

//array도 복사로 됨 -> 레퍼런스로 사용
void printLength(array<int, 5>& my_arr)
{
	cout << my_arr.size() << endl;
}

int main()
{
	//단점:크기 숫자가 꼭 있어야함
	std::array<int, 5> my_arr{ 1,21,3,40,5 };

	cout << my_arr[0] << endl;
	cout << my_arr.at(0) << endl;
	
	//cout << my_arr.at(10) << endl;
	//cout << my_arr[10] << endl;

	cout << my_arr.size() << endl;
	printLength(my_arr);

	cout << endl;
	for (auto element : my_arr)
		cout << element << endl;
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end());

	for (auto element : my_arr)
		cout << element << endl;
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend());
	
	for (auto element : my_arr)
		cout << element << endl;
	cout << endl;

	return 0;
}