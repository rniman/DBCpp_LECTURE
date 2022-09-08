#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//flag����
	//showpos->+ ���
	cout.setf(std::ios::showpos);
	cout << 108 << endl;

	//���� �ǵ���
	cout.unsetf(std::ios::showpos);
	cout << 108 << endl;

	//16������ ������� 
	//setf��� unsetf�� ���� 10������ ������
	//cout.unsetf(std::ios::dec); 
	//cout.setf(std::ios::hex);
	//cout.setf(std::ios::hex,std::ios::basefield);
	cout << std::hex;

	//16������ ���ĺ��� �빮�ڷ� ���
	//cout.setf(std::ios::uppercase);
	cout << std::uppercase;

	cout << 108 << endl;

	//bool�� true false
	cout << boolalpha;
	cout << true << ' ' << false << endl;

	//���е�
	//cout << std::defaultfloat;
	cout << std::showpoint;//���� �����
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