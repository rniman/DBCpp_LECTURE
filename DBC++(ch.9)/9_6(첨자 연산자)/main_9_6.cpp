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

	//const를 앞에 붙이면 값을 바꿀수 없다
	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index < 10);
		return m_list[index];
	}

};

int main()
{
	//()가 있으니 보기 불편 ->[]연산자 
	IntList my_list;
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 10;
	cout << my_list.getItem(3) << endl;

	my_list[3] = 15;
	cout << my_list[3] << endl;


	//값을 바꿀수 없어짐
	//const IntList list_1;
	
	IntList* list = new IntList[3];
	list[2][3] = 10;
	cout << list[2][3] << endl;
	

	return 0;
}