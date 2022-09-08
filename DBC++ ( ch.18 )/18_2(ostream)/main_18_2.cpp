#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//flag설정
	//showpos->+ 출력
	cout.setf(std::ios::showpos);
	cout << 108 << endl;

	//설정 되돌림
	cout.unsetf(std::ios::showpos);
	cout << 108 << endl;

	//16진수로 출력해줌 
	//setf경우 unsetf을 통해 10진수를 꺼야함
	//cout.unsetf(std::ios::dec); 
	//cout.setf(std::ios::hex);
	//cout.setf(std::ios::hex,std::ios::basefield);
	cout << std::hex;

	//16진수의 알파벳을 대문자로 출력
	//cout.setf(std::ios::uppercase);
	cout << std::uppercase;

	cout << 108 << endl;

	//bool값 true false
	cout << boolalpha;
	cout << true << ' ' << false << endl;

	//정밀도
	//cout << std::defaultfloat;
	cout << std::showpoint;//점을 찍어줌
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;


	cout << std::fixed;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;

	cout << std::defaultfloat;
	cout << std::scientific;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;

	cout << std::dec;
	cout.fill('*');
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;


	return 0;
}