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

//Mother class ���
class Child : public Mother
{
private:
	double m_d;

public:
	//Child �����ڰ� ȣ��ɶ� Mother�����ڵ� ���� �ڵ����� ȣ��� -> :Mother(i_in)���� �����ؼ� ȣ��

	/*Child()
	{}*/

	Child(const int& i_in, const double& d_in)
		//:m_i(i_in),m_d(d_in) -> m_i�� ��������
		//Mother������ ���⼭ �ذ�
		:Mother(i_in), m_d(d_in)
	{
		//Mother::setValue(i_in);
		//m_d = d_in;
	}

	//Mother class�� ��ġ�� �Լ� -> ������ class�� �켱������ ����
	void setValue(const double& d_in)
	{
		m_d = d_in;
	}

	void setValue(const int& i_in, const double& d_in)
	{
		//protected�� Mother ����� �ڽĵ��� ���� �� �� �ִ�
		m_i = i_in;
		m_d = d_in;

		//private�� ����Ѵٸ�
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