#include "Storage.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

//특수한 경우를 둘수있다
template<>
char getMax(char x, char y)
{
	cout << "Warning!(char)" << endl;
	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax('1', '2') << endl << endl;

	Storage<int> iValue = 5;
	Storage<double> dValue = 5.5;

	iValue.print();
	dValue.print();

	return 0;
}