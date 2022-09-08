#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main()
{
	using namespace std;

	float f(3.141592f);
	double d(0.1)	;
	long double ld(3.141592);

	float temp(123456789.0f); // 10 significant digits(유효숫자)

	cout << 1.0 / 3.0 << endl;
	cout << d << endl;
	//<iomanip>에 존재
	cout << setprecision(17);
	cout << 1.0 / 3.0 << endl;
	cout << d << endl;
	
	cout << temp << endl;//정밀도가 떨어짐

	cout << endl;

	double zero{ 0.0 };
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	cout << posinf << ' ' << isinf(posinf) << endl;
	cout << neginf << ' ' << isinf(neginf) << endl;
	cout << nan << ' ' << isnan(nan) << endl;
	cout << nan <<' ' << isnan(1.0) << endl;


	//3.14e1 == 3.14*10
	//cout << 3.14 << endl;
	//cout << 3.14e-1 << endl;
	//cout << 3.14e-2 << endl;
	//cout << 3.14e1 << endl;
	//cout << 3.14e2 << endl;


	//cout << sizeof(f) << endl;
	//cout << sizeof(d) << endl;
	//cout << sizeof(ld) << endl;

	//cout << numeric_limits<float>::max() << endl;
	//cout << numeric_limits<double>::max() << endl;
	//cout << numeric_limits<long double>::max() << endl;

	//cout << numeric_limits<float>::min() << endl;
	//cout << numeric_limits<double>::min() << endl;
	//cout << numeric_limits<long double>::min() << endl;

	//cout << numeric_limits<float>::lowest() << endl;
	//cout << numeric_limits<double>::lowest() << endl;
	//cout << numeric_limits<long double>::lowest() << endl;

	return 0;
}