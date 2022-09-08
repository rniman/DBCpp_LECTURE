#include <iostream>
#include <string>

using namespace std;

int main()
{

	string first_str("012345678");
	

	//string은 길이를 가지고 있어서 \0가 들어가지않음
	cout << first_str.size() << endl;

	cout << first_str.length() << endl;

	//reallocation을 되도록 피하고 싶어하기에 여유분을 남겨둠
	cout << first_str.capacity() << endl;
	first_str.reserve(1000);
	cout << first_str.capacity() << endl;


	cout << first_str.max_size() << endl;
	
	cout << boolalpha;
	cout << first_str.empty() << endl;

	string second_str("");
	cout << second_str.empty() << endl;

	return 0;
}