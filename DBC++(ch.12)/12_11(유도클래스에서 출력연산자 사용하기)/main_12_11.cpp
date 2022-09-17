#include <iostream>
class Base
{
public:
	Base() {}


	//������� ����� �ƴϹǷ� �������̵��� �Ұ���
	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Der : public Base
{
public:
	Der() {}

	virtual std::ostream& print(std::ostream& out)const override 
	{
		out << "Der";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << std::endl;

	Der d;
	std::cout << d << std::endl;

	Base& t = d;
	std::cout << t << std::endl;
}