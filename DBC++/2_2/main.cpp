#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	cout << std::pow(2, sizeof(short)* 8 - 1) - 1 << endl;
	cout << std::numeric_limits<unsigned int>::max() << endl;
	cout << std::numeric_limits<short>::min() << endl;
	cout << std::numeric_limits<short>::lowest() << endl;

	return 0;
}