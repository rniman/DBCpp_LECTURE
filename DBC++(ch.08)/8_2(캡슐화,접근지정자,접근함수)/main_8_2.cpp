#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
public:		//access specifier 접근 지정자 
	//외부에서 접근 가능
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
private:	//public이 없다면 private가 기본

};

class Date_another
{
	//후에 멤버 변수명을 바꾸고 싶을때 public으로 되어 있다면 class외부에도 똑같이 이름을 바꿔줘야함
	//private로 되어 있다면 class 내부에서 이름을 바꾸면 끝나게 됨 -> 그래서 public에 함수로 초기화를 시켜주는 것
	int m_month;
	int m_day;
	int m_year;
public:
	//멤버에 접근하기 위한 함수
	//같은 클래스내에서는 private변수에 접근 가능
	//나중에 생성자를 통해서 더 간략히 가능
	//출력또한 접근할 수 없으므로 따로 함수를 만들어 줘야한다
	void setDate(const int& input_month, const int& input_day, const int& input_year)
	{
		m_month = input_month;
		m_day = input_day;
		m_year = input_year;
	}
	//setMonth ...

	//카피
	//다른 주소의 객체도 같은 클래스라면 private에 접근 가능함 ->origin에 접근함
	void copyFrom(const Date_another& origin)
	{
		m_month = origin.m_month;
		m_day = origin.m_day;
		m_year = origin.m_year;
	}

	//const 레퍼런스로 출력만 가능하게 해줌
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