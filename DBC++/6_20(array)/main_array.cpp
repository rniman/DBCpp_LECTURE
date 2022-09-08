#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

//array�� ����� �� -> ���۷����� ���
void printLength(array<int, 5>& my_arr)
{
	cout << my_arr.size() << endl;
}

int main()
{
	//����:ũ�� ���ڰ� �� �־����
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