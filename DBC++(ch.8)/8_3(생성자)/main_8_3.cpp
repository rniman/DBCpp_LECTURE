#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	//반환값이 없고 class명이 같으면 생성자
	//외부에서 호출 X
	//선언이 됨과 동시에 생성자 실행됨
	//생성자가 없을때는 default생성자가 기본적으로 숨어있다 ->생성자가 하나라도 생기면 default생성자는 없어짐
	//생성자를 private에 놓으면 지금 상황에서는 안됨
	Fraction()
	{
		m_numerator = 1;
		m_denominator = 1;
	}
	
	Fraction(const int& num_in , const int& den_in = 1)
	{
		m_numerator = num_in;
		m_denominator = den_in;
	}

	
	void print()
	{
		cout << m_numerator << " / " << m_denominator << endl;
	}
};

class Second
{

public:
	Second()
	{
		cout << "Second On" << endl;
	}
};

class First
{
	Second sec;
public:
	First()
	{
		cout << "First On" << endl;
	}
};

int main()
{
	Fraction frac;
	Fraction frac2(3, 5);

	//형변환 안해줌
	Fraction frac4{ 3 , 7 };

	//권장X
	Fraction frac3 = Fraction{ 3 , 3 };

	frac.print();
	frac2.print();
	frac4.print();

	//class안에 class가 있다면 내부의 class를 먼저 생성함
	First fir;
	

	return 0;
}
