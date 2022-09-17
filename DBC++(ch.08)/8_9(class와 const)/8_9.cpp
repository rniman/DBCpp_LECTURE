#include <iostream>
using namespace std;

class Something
{
public:

	//���� constructor ->�Լ����� �Ķ���ͷ� Ŭ������ ������ ���� constructor�� �����
	//�⺻������ ���� ����
	Something(const Something& st_in)
	{
		cout << "copy" << endl;
		m_value = st_in.m_value;
	}

	Something()
	{
		cout << "Constructor" << endl;
	}
	 
	int m_value = 0;

	void setValue(int value) { m_value = value; }
	
	//const �� �ڿ� ���̸� const class���� ��밡������
	int getValue() const
	{
		return m_value; 
	}
};

//���簡 �Ͼ -> const reference�� ����� -> ���簡 ����
void Print(Something st)
{
	cout << st.m_value << endl;
	cout << &st << endl;
}

int main()
{
	//��� m_value�� const�� ��
	const Something something;
	

	//const ���� ���� �Ұ�
	//something.setValue(3);

	//member function �ڿ� const�� �ٿ��� ��� ����
	cout << something.getValue() << endl;

	cout << endl;
	Something temp;
	Print(temp);
	cout << &temp << endl;


	return 0;
}