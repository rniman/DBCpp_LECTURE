#include <iostream>

int main()
{

	using namespace std;

	int x = 1;
	int y = 1;
	int z = (++x, ++y);

	cout << z << endl;
	

	int a = 1;
	int b = 1;
	int c;
	c = 2, 3; //,�� =���� �켱������ ����

	cout << c << endl;


}