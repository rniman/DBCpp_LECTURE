#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };


	//함수와 같이 바뀌지 않음	
	for (int number : fibonacci)
		number = 10;

	for (int number : fibonacci)
		cout << number << " ";
	cout << endl;

	//레퍼런스를 이용하면 바뀜
	for (int& number : fibonacci)
		number = 10;


	for (const int &number : fibonacci)
		cout << number << " ";
	cout << endl;

	int max_num = std::numeric_limits<int>::lowest();

	for (const auto& n : fibonacci)
		max_num = std::max(max_num, n);
	cout << max_num << endl;

	//동적할당시 for - each 사용 불가능 -> vector 사용

	std::vector<int> fibonacci_vec = { 0,1,1,2,3,5,8,13,21,34,55,89 };


	return 0;
}