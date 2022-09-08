#include <iostream>
using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:

	Accumulator(const int& acc_1)
		:m_counter(acc_1)
	{
		//m_counter = acc_1;
	}

	int& operator()(int i) { return (m_counter += i); }

	operator int()
	{
		cout << "cast" << endl;
		return m_counter;
	}
	operator double()
	{
		cout << "cast double" << endl;
		return m_counter;
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

void printDouble(const double &value)
{
	cout << value << endl;
}

int main()
{
	Accumulator acc(5);

	cout << acc(10) << endl;
	cout << acc(20) << endl;

	printInt(acc);
	printDouble(acc);
	return 0;
}