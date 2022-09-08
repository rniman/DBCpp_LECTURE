#include <iostream>
using namespace std;



class Mother
{
protected:
	int m_i;

public:
	//Mother()
	//	:m_i(0)
	//{}

	Mother(const int& i_in)
		:m_i(i_in)
	{
		cout << "Mother Constructor" << endl;
	}  

	void setValue(const int& i_in)
	{
		m_i = i_in;
	}

	int getValue() const
	{
		return m_i;
	}

};

//Mother class 상속
class Child : public Mother
{
private:
	double m_d;

public:
	//Child 생성자가 호출될때 Mother생성자도 같이 자동으로 호출됨 -> :Mother(i_in)으로 지정해서 호출

	/*Child()
	{}*/

	Child(const int& i_in, const double& d_in)
		//:m_i(i_in),m_d(d_in) -> m_i가 막혀있음
		//Mother생성을 여기서 해결
		:Mother(i_in), m_d(d_in)
	{
		//Mother::setValue(i_in);
		//m_d = d_in;
	}

	//Mother class와 겹치는 함수 -> 본인의 class가 우선순위가 높다
	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		//protected의 Mother 멤버를 자식들이 접근 할 수 있다
		m_i = i_in;
		m_d = d_in;

		//private를 사용한다면
		//Mother::setValue(i_in);
	}

	double getValue() const
	{
		return m_d;
	}

};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother(1024);
	//mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 64);
	//child.setValue(64);
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;
}