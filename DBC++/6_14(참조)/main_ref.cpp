#include <iostream>

using namespace std;

//const�� �Ű������� �ٿ��ִ� ���� �Լ������� ���� �ٲܼ� ����
//���簡 �Ͼ�� ����
void doSomething(/*const*/ int &n)
{

	n = 10;
	cout << "in doSomething" << n << " " << &n << endl;
}

//const�� ������ �Լ� ȣ��� �������ƴ� ���ڵ� �Ű������� ����� ������
void doSomething2(const int& x)
{
	cout << endl << "DoSomething2" << endl;
	cout << &x << endl;
	cout << x << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main()
{
	int value{ 5 };

	//pointer
	int* ptr = nullptr;
	ptr = &value;

	//reference -> ����
	//1.�ݵ�� �ʱ�ȭ�� �Ǿ���ϰ� ���ͷ��� ����
	int& ref = value;


	cout << ref << endl;

	ref = 10;

	cout << value << endl;
	cout << ref << endl;

	cout << endl << "�ּҰ�\n";
	cout << &value << endl;
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;

	//const �������� ������� ���� 
	//const�� ���̸� ����
	/*const int y = 8;
	int& ref2 = y;*/
	const int y = 8;
	const int& ref2 = y;

	cout << endl;
	int value1 = 5;
	int value2 = 10;

	int &ref3 = value1;
	
	cout << ref3 << endl;
	
	//value1�� ���� ���� �ٲ����
	ref3 = value2; 

	cout << ref3 << endl;

	//�Լ��� ���۷��� �̿��ϱ�
	int n = 5;
	cout << endl << n << " " << &n << endl;
	doSomething(n);
	cout << n << endl;

	
	
	
	//Ÿ������ �������
	Other ot;
	ot.st.v1 = 1.0;

	//���۷����� �̿��ؼ� �����ϰ� ��밡��
	float& v2 = ot.st.v2;
	v2 = 2.3;

	//�����Ϳ� ���۷����� �����ϰ� �۵�
	int  value_0 = 5;
	int* const ptr_0 = &value_0;
	int& ref_0 = value_0;


	int x = 5;
	const int &ref_x = x;
	const int& ref_x2 = ref_x;

	
	const int& ref_num = 5 + 4;
	const int ref_num1 = 4 + 3;
	
	//�Ű������� const�� ������ �Լ� ȣ��� �������ƴ� ���ڵ� �Ű������� ����� ������
	doSomething2(1000);
	
	return 0;
}