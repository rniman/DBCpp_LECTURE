#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	char buf[5];

	//setw -> �ִ� ���ڼ� ��ŭ ������ �ֵ��� ��������
	cin >> setw(5) >> buf;

	cout << buf << endl;


	//���ۿ� ���ڰ� �����ִٸ� ������
	cin >> setw(5) >> buf;

	cout << buf << endl;


	//��ĭ�� �о�帲 ���۸� ������� ����
	cin.get(buf, 5);
	
	//��ĭ�� �о�帲 �Է��� ���� �� �޾Ƽ� ���۰� �����
	//\0�� �о����� gcount�� 1�� ������
	cin.getline(buf, 5);


	//����� �о�Դ��� �˼�����
	cout << cin.gcount();

	string str_buf;

	getline(cin, str_buf);
	//0�� ����Ѵ�
	cout << cin.gcount() << endl;

	//���ڸ�ŭ �Է��� ���ڿ��� �պκ��� ������
	cin.ignore(/*����*/);

	//���ۿ��� ���ڸ� �о������ ���ۿ� �״�� ���ܵд�
	cout << (char)cin.peek() << endl;

	//���۸� ������ �������� ���� ���ڸ� ���ۿ� �ٽó���
	cin.unget();

	//���ۿ� 'A'�� ����
	cin.putback('A');

	return 0;
}