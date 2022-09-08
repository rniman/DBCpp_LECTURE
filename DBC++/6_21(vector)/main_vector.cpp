#include <iostream>
#include <vector>
//동적 할당


using namespace std;

int main()
{
	std::vector<int> my_arr = { 1,2,3,4,5 };

	std::vector<int> my_arr2 = { 1,2,3,4,5 };
	
	cout << my_arr2.size() << endl;

	std::vector<int> my_arr3 { 1,2,3, };

	cout << my_arr3.size() << endl;

	for (auto& itr : my_arr)
		cout << itr << " ";
	cout << endl;

	cout << my_arr[1] << endl;
	cout << my_arr.at(1) << endl;

	cout << endl;
	cout << my_arr.size() << endl;
	my_arr.resize(10);
	cout << my_arr.size() << endl;
	my_arr.resize(2);
	cout << my_arr.size() << endl;

	return 0;
}