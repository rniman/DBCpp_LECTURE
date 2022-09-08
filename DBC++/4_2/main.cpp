#include <iostream>
#include <string>
#include <limits>

int main()
{
	using namespace std;

	const char my_strs[] = "hello, world";
	const string my_hello = "hello, world";

	cout << my_hello << endl;

	int age;
	cin >> age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max()/*32767*/, '\n');

	string name;
	//enter까지 버퍼를 안비움
	std::getline(std::cin, name); 
	string initial{ "ZZANG" };

	string nickName = name + initial;

	cout << nickName << " " << nickName.length() << endl;
	cout << age << endl;
	
	return 0;
}