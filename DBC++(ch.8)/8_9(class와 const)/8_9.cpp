#include <iostream>
using namespace std;

class Something
{
public:

	//복사 constructor ->함수에서 파라미터로 클래스를 받을때 복사 constructor가 실행됨
	//기본적으로 숨어 있음
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
	
	//const 를 뒤에 붙이면 const class사용시 사용가능해짐
	int getValue() const
	{
		return m_value; 
	}
};

//복사가 일어남 -> const reference를 사용함 -> 복사가 없음
void Print(Something st)
{
	cout << st.m_value << endl;
	cout << &st << endl;
}

int main()
{
	//멤버 m_value가 const가 됨
	const Something something;
	

	//const 사용시 변경 불가
	//something.setValue(3);

	//member function 뒤에 const를 붙여야 사용 가능
	cout << something.getValue() << endl;

	cout << endl;
	Something temp;
	Print(temp);
	cout << &temp << endl;


	return 0;
}