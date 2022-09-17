using namespace std;

//this는 class 자신의 주소를 알려줌
//this는 class 내에 항상 숨어있음

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{}

	//연쇄호출
	Calc& add(int value)
	{
		m_value += value;
		return *this;
	}
	Calc& sub(int value)
	{
		m_value -= value;
		return *this;
	}
	Calc& mult(int value)
	{
		m_value += value;
		return *this;
	}
	void print()
	{
		cout << m_value << endl;
	}
};

int main()
{
	Calc temp(10);
	
	temp.add(10).sub(10).mult(2).print();


}