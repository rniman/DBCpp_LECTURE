#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>
std::string ToString(T x)
{
	std::ostringstream osstream;

	osstream << x;

	return osstream.str();
}

template<typename T>
bool FromString(const string& str, T &x)
{
	std::istringstream isstream(str);

	return (isstream >> x) ? true : false;
}

int main()
{
	std::string my_string("my string");
	//const char* my_string = "my string";

	//std::string second_str(my_string);
	//std::string second_str(my_string, 3); //뒤의 숫자만큼 앞의 문자열을 자름 - c스타일 문자열이면 뒤의 숫자만큼 가져옴
	//std::string second_str(my_string, 3 , 5); //뒤의 숫자만큼 앞의 문자열을 자르고 마지막 숫자만큼 가져옴
	string second_str(10, 'a'); //문자를 숫자만큼 채워넣음
	
	cout << my_string << endl;
	cout << second_str << endl;

	std::vector<char>vec;

	for (auto e : "Today is rainy day")
		vec.push_back(e);

	//string third_str(vec.begin(), vec.end());
	string third_str(vec.begin(), std::find(vec.begin(),vec.end(),'n')); //find이용

	cout << third_str << endl;

	//to_string 숫자를 문자열로 바꿔줌
	string forth_str(std::to_string(1004));
	cout << forth_str << endl;

	//뒤에 붙일수도 있다
	forth_str += std::to_string(100);
	cout << forth_str << endl;

	int temp_i = std::stoi(forth_str);
	cout << temp_i << endl;

	string fifth_str(ToString(9.11));
	cout << fifth_str << endl;

	double d;
	if (FromString(fifth_str, d))
		cout << d << endl;
	else
		cout << "false" << endl;

	if (FromString(second_str, d))
		cout << d << endl;
	else
		cout << "false" << endl;


	return 0;
}