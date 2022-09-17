#include <iostream>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents()
	{

	}
	Cents(int cents) { m_cents = cents; }

	int getCents() const { return m_cents; }
	int& getCents() { return m_cents; }


	Cents operator - ()const
	{
		return -m_cents;
	}

	bool operator ! ()const
	{
		if (m_cents == 0) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend Cents operator +(const Cents& c1, const Cents& c2);

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}
};


Cents operator +(const Cents& c1, const Cents& c2)
{
	//return Cents(c1.getCents() + c2.getCents());
	return Cents(c1.m_cents + c2.m_cents);
}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	//auto°¡ boolÇüÀÌ µÊ
	auto a = !cents1;

	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;
	cout << -cents1 << endl;
	cout << !cents1 << endl;
}

