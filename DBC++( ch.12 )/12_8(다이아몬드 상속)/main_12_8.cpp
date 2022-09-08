#include <iostream>
using namespace std;

class PowerDevice
{
public:
	int m_i;

	PowerDevice(int power)
	{
		cout << "PowerDevice: " << power << endl;
	}
};

class Scanner : virtual public PowerDevice
{
public:
	Scanner(int scanner, int power)
		:PowerDevice(power)
	{
		cout << "Scanner: " << scanner << endl;
	}

};

class Printer :virtual public PowerDevice
{
public:
	Printer(int printer, int power)
		:PowerDevice(power)
	{
		cout << "Printer: " << printer << endl;
	}

};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		:Scanner(scanner,power), Printer(printer,power),PowerDevice(power)
	{}

};

int main()
{
	Copier cop(1, 2, 3);

	//주소가 다름 -> virtual을 붙혀주면 같아짐
	cout << &cop.Scanner::PowerDevice::m_i << endl;
	cout << &cop.Printer::PowerDevice::m_i << endl;


	return 0;
}