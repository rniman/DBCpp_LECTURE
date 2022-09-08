#include <iostream>
#include <cmath>

int main()
{
	double d1{ 100 - 99.99 };
	double d2{ 10 - 9.99 };

	const double epsilon = 1e-10;

	//abs는 절대값
	if (std::abs(d1 - d2) < epsilon) {
		std::cout << "Approximately equal" << std::endl;
	}
	else {
		std::cout << "Not equal" << std::endl;
	}
	return 0;
}