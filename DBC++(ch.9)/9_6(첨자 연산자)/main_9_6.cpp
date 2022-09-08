#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10];

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	int* getList()
	{
		return m_list;
	}

	//const�� �տ� ���̸� ���� �ٲܼ� ����
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

};

int main()
{
	//()�� ������ ���� ���� ->[]������ 
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getItem(3) << endl;

	my_list[3] = 15;
	cout << my_list[3] << endl;


	//���� �ٲܼ� ������
	//const IntList list_1;
	
	IntList* list = new IntList[3];
	list[2][3] = 10;
	cout << list[2][3] << endl;
	

	return 0;
}