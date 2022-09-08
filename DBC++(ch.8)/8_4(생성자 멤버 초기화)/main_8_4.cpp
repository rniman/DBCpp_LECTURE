#include <iostream>
using namespace std;

class B
{
private:
	int m_b;

public:
	B(const int& m_b_in) :m_b(m_b_in)
	{

	}

	void print()
	{
		cout << m_b << endl;
	}
};

class Something
{
private:
	//private 에서도 초기화를 해주면 생성자가 우선순위가 높다
	int	   m_i = 2;
	double m_d = 5.5;
	char   m_c = 'b';
	int	   m_arr[5] = {10,11,12,13,14};
	B      m_b = 1000;

public:
	Something()
		: m_i{ 1 }, m_d{ 3.14 }, m_c{'a'},m_arr{1,2,3,4,5}, m_b(m_i - 1)
	{
		//m_i = 1;
		//m_d = 3.14;
		//m_c = 'a';
	}

	void print()
	{
		cout << m_i << " " << m_d << " " << m_c << endl;
		for (auto& e : m_arr)
			cout << e << " ";
		cout << endl;
		m_b.print();
	}
};

int main()
{
	Something some;
	some.print();
	return 0;
}