#include <iostream>
using namespace std;

class Something
{
public:

	//�̳� Ŭ����
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	
	//static ��� ������ �̰����� �ʱ�ȭ ���� �� �� ���� 
	//Ŭ���� �ȿ��� �ʱ�ȭ �ϱ����ؼ� �̳� Ŭ������ �̿��ؾ���
	Something()
		:m_value(123)/*, s_value(100)*/
	{}

	static int getValue()
	{
		//static ��� �Լ��� this-> �� ��� �� �� ����
		//m_value ���� this->m_value�̹Ƿ� ��� �Ұ���
		
		return s_value;
	}

	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;
//s_initializer�����ڰ� �����Ǹ鼭 s_value�� �ʱ�ȭ ����
Something::_init Something::s_initializer;


int main()
{
	//s_value ���� �Ұ��� -> ��� �Լ��� static���� ����
	cout << Something::getValue() << endl;
	Something s1;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;


	//class������ ��� �Լ��� ��� ��ü�� �ּҰ� ����
	int (Something:: * fptr1)() = &Something::temp;

	cout << (s1.*fptr1)() << endl;

	//static ��� �Լ�
	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;


	return 0;
}