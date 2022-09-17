#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1("one");

	string str2;
	str2 = str1;
	str2 = "two";
	str2.assign("one two").append(" ").append("three");//append µ¡ºÙ¿©ÁÜ
	str2 += " four";
	
	str2.push_back('P');

	cout << str1 << endl;
	cout << str2 << endl;

	str2.pop_back();	
	str2.insert(0, "shin ");

	cout << str1 << endl;
	cout << str2 << endl;

	std::swap(str1, str2);

	cout << str1 << endl;
	cout << str2 << endl;

	str1.swap(str2);

	cout << str1 << endl;
	cout << str2 << endl;



	return 0;
}