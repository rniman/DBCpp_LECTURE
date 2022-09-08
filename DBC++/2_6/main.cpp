#include <iostream>


bool isEqual(int a, int b)
{
	bool result = (a == b);
	return result;
}

int main()
{
	using namespace std;

	bool b1 = true;
	bool b2(false);
	bool b3{ true };
	b3 = false;

	cout << std::boolalpha;
	cout << b1 << endl << !b1 << endl << b2 << endl << b3 << endl;

	cout << endl;
	cout << (true && true) << endl;
	cout << (true && false) << endl;
	cout << (false && true) << endl;
	cout << (false && false) << endl;

	cout << endl;
	cout << (true || true) << endl;
	cout << (true || false) << endl;
	cout << (false || true) << endl;
	cout << (false || false) << endl;

	cout << endl;
	if (false)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;


	cout << endl;
	cout << isEqual(1, 1) << endl;
	cout << isEqual(1, 3) << endl;

	return 0;
}