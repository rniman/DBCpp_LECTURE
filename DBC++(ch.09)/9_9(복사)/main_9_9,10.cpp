#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	//Delete 막아버림
	Fraction(char) = delete;

	//explicit 정확하게 적어라
	explicit Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}


	//복사 생성자 -> 자기와 똑같은 것이 들어옴
	//복사를 막으려면 private로 옮겨준다
	Fraction(const Fraction& frac)
		:m_numerator(frac.m_numerator), m_denominator(frac.m_denominator)
	{
		cout << "copy constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& frac)
	{
		cout << frac.m_numerator << " / " << frac.m_denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	return temp;
}

void doSomething_2(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(3, 5);
	Fraction frac_copy(frac);
	Fraction frac_copy1 = frac;
	
	//복사하지 않음
	Fraction frac_copy2(Fraction(3,10));

	//release모드로 실행하면 복사하지않음->반환값 최적화
	Fraction temp = doSomething();

	cout << frac << frac_copy << endl;

	Fraction frac_2(7);
	doSomething_2(frac_2);
	
	//explicit 이 있다면 작동 하지 않음
	//doSomething_2(6);

	//삭제된 함수
	Fraction frac_3('C');
	return 0;
}