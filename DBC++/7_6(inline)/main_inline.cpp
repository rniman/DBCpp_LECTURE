#include <iostream>

using namespace std;

//�Լ��� �ƴѰ�ó�� ��
//inline�� ������ ���� -> �������� ����
//�ֱٿ��� inline�� ���°� �ǹ̰� ������ �ǹ��� ����
inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
	
	//inline �Լ��� ����
	cout << (5 > 6 ? 6 : 5) << endl;

	return 0;
}