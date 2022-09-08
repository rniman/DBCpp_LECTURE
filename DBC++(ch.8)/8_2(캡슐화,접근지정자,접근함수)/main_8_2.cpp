#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
public:		//access specifier ���� ������ 
	//�ܺο��� ���� ����
	int m_month;
	int m_day;
	int m_year;

	void setDate(const int& input_month, const int& input_day, const int& input_year)
	{
		m_month = input_month;
		m_day = input_day;
		m_year = input_year;
	}

	void copyFrom(const Date& origin)
	{
		m_month = origin.m_month;
		m_day = origin.m_day;
		m_year = origin.m_year;
	}
private:	//public�� ���ٸ� private�� �⺻

};

class Date_another
{
	//�Ŀ� ��� �������� �ٲٰ� ������ public���� �Ǿ� �ִٸ� class�ܺο��� �Ȱ��� �̸��� �ٲ������
	//private�� �Ǿ� �ִٸ� class ���ο��� �̸��� �ٲٸ� ������ �� -> �׷��� public�� �Լ��� �ʱ�ȭ�� �����ִ� ��
	int m_month;
	int m_day;
	int m_year;
public:
	//����� �����ϱ� ���� �Լ�
	//���� Ŭ������������ private������ ���� ����
	//���߿� �����ڸ� ���ؼ� �� ������ ����
	//��¶��� ������ �� �����Ƿ� ���� �Լ��� ����� ����Ѵ�
	void setDate(const int& input_month, const int& input_day, const int& input_year)
	{
		m_month = input_month;
		m_day = input_day;
		m_year = input_year;
	}
	//setMonth ...

	//ī��
	//�ٸ� �ּ��� ��ü�� ���� Ŭ������� private�� ���� ������ ->origin�� ������
	void copyFrom(const Date_another& origin)
	{
		m_month = origin.m_month;
		m_day = origin.m_day;
		m_year = origin.m_year;
	}

	//const ���۷����� ��¸� �����ϰ� ����
	const int& getDay()
	{
		return m_day;
	}
};

int main()
{
	Date today{ 8,4,2025 };

	Date_another today_another;
	today_another.setDate(8, 4, 2025);

	cout << today_another.getDay() << endl;

	Date_another copy;
	copy.copyFrom(today_another);
	cout << copy.getDay() << endl;

	return 0;
}