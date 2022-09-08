#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value = 0)
		:m_i(value)
	{}

	void print()
	{
		cout << "I'm Base" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		out << "This is base output" << endl;
		return out;
	}
};

class Derived : public Base
{
private:
	double m_d;

public:
	Derived(int value = 0)
		:Base(value)
	{}

	//�θ� class�� �Լ��̸��� ����
	void print()
	{
		//Base::�� ������ ����������� ȣ����
		Base::print();
		cout << "I'm Derived" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& b)
	{
		//����ƽ cast�� ���ؼ� opertator ȣ��
		cout << static_cast<Base>(b);
		out << "This is derived output" << endl;
		return out;
	}
};

int main()
{
	Base base(5);
	base.print();
	cout << base << endl;


	Derived derived(7);
	derived.print();
	cout << derived << endl;
}