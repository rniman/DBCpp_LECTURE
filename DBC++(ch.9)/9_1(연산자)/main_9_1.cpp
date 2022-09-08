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

	//멤버로만 구현해야하는 연산자	
	//  =  []  ()  ->

	//friend 사용안하면 this로 구현 해야함
	/*Cents operator +(const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents);
	}*/


	friend Cents operator +(const Cents& c1, const Cents& c2);

};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

Cents operator +(const Cents& c1, const Cents& c2)
{
	//return Cents(c1.getCents() + c2.getCents());
	return Cents(c1.m_cents + c2.m_cents);
}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents sum;
	

	cout << add(cents1, cents2).getCents() << endl;

	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;
}

