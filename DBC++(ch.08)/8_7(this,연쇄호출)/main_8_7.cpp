using namespace std;

//this�� class �ڽ��� �ּҸ� �˷���
//this�� class ���� �׻� ��������

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value)
		:m_value(init_value)
	{}

	//����ȣ��
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