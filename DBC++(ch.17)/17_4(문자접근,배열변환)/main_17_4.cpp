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
		// []���۷����Ϳ� ���ؼ��� ����ó�� ����
		//first_str[100] = 'E';

		first_str.at(100) = 'E';
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
	
	//string�� c��Ÿ���� ���ڿ��� �޴¹�
	//\0�� �ٿ��� ����
	cout << first_str.c_str() << endl;

	const char* arr = first_str.c_str();

	cout << (int)arr[6] << " " << arr[6] << endl;
	cout << (int)arr[7] << " " << arr[7] << endl;

	//copy
	char buf[20];
	//���� �迭, ä�� ����, ���°���� ������
	first_str.copy(buf, 5, 0);
	
	//\0�� �ڵ����� ���� ����
	cout << buf << endl;
	buf[5] = '\0';
	cout << buf << endl;

	return 0;
}