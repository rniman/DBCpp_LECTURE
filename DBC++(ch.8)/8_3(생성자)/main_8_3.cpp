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
	//��ȯ���� ���� class���� ������ ������
	//�ܺο��� ȣ�� X
	//������ �ʰ� ���ÿ� ������ �����
	//�����ڰ� �������� default�����ڰ� �⺻������ �����ִ� ->�����ڰ� �ϳ��� ����� default�����ڴ� ������
	//�����ڸ� private�� ������ ���� ��Ȳ������ �ȵ�
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

	//����ȯ ������
	Fraction frac4{ 3 , 7 };

	//����X
	Fraction frac3 = Fraction{ 3 , 3 };

	frac.print();
	frac2.print();
	frac4.print();

	//class�ȿ� class�� �ִٸ� ������ class�� ���� ������
	First fir;
	

	return 0;
}
