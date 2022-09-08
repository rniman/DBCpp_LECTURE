#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string first_str("abcdefg");

	cout << first_str[0] << endl;
	cout << first_str[5] << endl;

	first_str[0] = 'A';
	cout << first_str << endl;

	try
	{
		// []오퍼레이터에 대해서는 예외처리 없음
		//first_str[100] = 'E';

		first_str.at(100) = 'E';
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	//string을 c스타일의 문자열로 받는법
	//\0을 붙여서 넣음
	cout << first_str.c_str() << endl;

	const char* arr = first_str.c_str();

	cout << (int)arr[6] << " " << arr[6] << endl;
	cout << (int)arr[7] << " " << arr[7] << endl;

	//copy
	char buf[20];
	//넣을 배열, 채울 갯수, 몇번째부터 넣을지
	first_str.copy(buf, 5, 0);
	
	//\0가 자동으로 들어가지 않음
	cout << buf << endl;
	buf[5] = '\0';
	cout << buf << endl;

	return 0;
}