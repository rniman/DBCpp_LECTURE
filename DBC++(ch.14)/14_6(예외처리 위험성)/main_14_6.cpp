//1.�޸� ���� �߻��Ҽ�����
//2.�Ҹ��ڿ����� ����ó���� �Ҽ�����
//3.��� ������ ����ó���� ������ ��������

#include <iostream>
#include <memory>//����Ʈ������

using namespace std;


class A
{
public:
	//~A()
	//{
	//	//�Ҹ��ڿ����� ����ó���� �����Ǿ�����
	//	throw "error";
	//}
};

int main()
{

	//�޸𸮴���
	try
	{
		int *i = new int[1000000];
		
		//����ũ ������ ����ϸ� delet�� �ʿ������
		//throw�ÿ��� �˾Ƽ� delete������
		unique_ptr<int> up_i(i);

		throw "error";

		delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	try
	{
		A a;
	}
	catch (...)
	{
		cout << "A Catch" << endl;
	}

}