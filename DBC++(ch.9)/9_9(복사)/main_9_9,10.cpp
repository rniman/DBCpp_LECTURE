#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	//Delete ���ƹ���
	Fraction(char) = delete;

	//explicit ��Ȯ�ϰ� �����
	explicit Fraction(int num = 0, int den = 1)
		:m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}


	//���� ������ -> �ڱ�� �Ȱ��� ���� ����
	//���縦 �������� private�� �Ű��ش�
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
	
	//�������� ����
	Fraction frac_copy2(Fraction(3,10));

	//release���� �����ϸ� ������������->��ȯ�� ����ȭ
	Fraction temp = doSomething();

	cout << frac << frac_copy << endl;

	Fraction frac_2(7);
	doSomething_2(frac_2);
	
	//explicit �� �ִٸ� �۵� ���� ����
	//doSomething_2(6);

	//������ �Լ�
	Fraction frac_3('C');
	return 0;
}