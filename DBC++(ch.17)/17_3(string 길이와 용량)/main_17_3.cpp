#include <iostream>
#include <string>

using namespace std;

int main()
{

	string first_str("012345678");
	

	//string�� ���̸� ������ �־ \0�� ��������
	cout << first_str.size() << endl;

	cout << first_str.length() << endl;

	//reallocation�� �ǵ��� ���ϰ� �;��ϱ⿡ �������� ���ܵ�
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