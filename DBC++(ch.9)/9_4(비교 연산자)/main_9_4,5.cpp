#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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


	Cents operator - ()const
	{
		return -m_cents;
	}

	//���� ����
	Cents& operator ++()
	{
		++m_cents;
		return *this;
	}

	//���� ���� -> �Ķ���Ϳ� ���̷� �ƹ��ų� �־����
	Cents operator ++(int)
	{
		Cents temp(m_cents);
		//++m_cents;
		++(*this);
		return temp;
	}


	//sort�� ���� �� ������ ���۷����ʹ� >�� �ƴ� <�� �ؾ���
	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
	}


	bool operator ! ()const
	{
		return (m_cents == 0) ? true : false;
	}

	friend Cents operator +(const Cents& c1, const Cents& c2);

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out;
	}

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

};


Cents operator +(const Cents& c1, const Cents& c2)
{
	//return Cents(c1.getCents() + c2.getCents());
	return Cents(c1.m_cents + c2.m_cents);
}

int main()
{


	Cents cents1(8);
	Cents cents2(8);

	//auto�� bool���� ��
	auto a = !cents1;

	if (cents1 == cents2) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}

	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;
	cout << -cents1 << endl;
	cout << !cents1 << endl;

	//
	vector<Cents> arr(20);
	for (int i = 0; i < 20; ++i) {
		arr[i].getCents() = i;
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(arr.begin(), arr.end(), g);

	//17���ķδ� �ȵ� -> �ٵ� �ֵǳ�???
	//std::random_shuffle(begin(arr), end(arr));

	//Cents�� ���� ũ�� �񱳸� ����
	std::sort(arr.begin(), arr.end());

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	
	//����������
	cout << ++cents1 << endl;;
	cout << cents1++ << endl;;
	cout << cents1 << endl;;

	

}

