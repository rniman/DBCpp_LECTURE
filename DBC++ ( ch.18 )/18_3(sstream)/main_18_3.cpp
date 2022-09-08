#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	stringstream os;
	string str;

	cout;
	//std::ostream os2;

	os << "Hello, world";

	os >> str;

	cout << str << endl;;

	os.str("hello, World");

	os >> str;

	cout << str << endl;

	str = os.str();

	cout << str << endl;

	os << "hi hi hi " << endl;

	str = os.str();

	cout << str << endl;

	stringstream os2;

	os2 << "12345 67.89";

	string str1;
	string str2;

	os2 >> str1 >> str2;

	cout << str1 << '|' << str2 << endl;

	int i = 12345;
	double d = 67.89;

	stringstream os3;

	os3 << i << " " << d;
	
	string str3;
	string str4;
	
	os3 >> str3 >> str4;

	cout << str3 << '|' << str4 << endl;

	int i2;
	double d2;

	stringstream os4;

	os4 << i << " " << d;

	os4 >> i2 >> d2;

	cout << i2 << '|' << d2 << endl;

	//stream ºñ¿öÁÜ
	str = os.str();

	cout << str << endl;

	os.str("");
	//os.str(string());

	str = os.str();

	cout << str << "¹¹°¡ ³ª¿À³Ä?" << endl;

	//state±îÁö clear¸¦ ½ÃÅ´
	os.clear();

	return 0;
}