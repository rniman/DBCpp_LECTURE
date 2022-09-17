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

	//전위 증감
	Cents& operator ++()
	{
		++m_cents;
		return *this;
	}

	//후위 증감 -> 파라미터에 더미로 아무거나 넣어야함
	Cents operator ++(int)
	{
		Cents temp(m_cents);
		//++m_cents;
		++(*this);
		return temp;
	}


	//sort를 위한 비교 연산자 오퍼레이터는 >이 아닌 <로 해야함
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

	//auto가 bool형이 됨
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

	//17이후로는 안됨 -> 근데 왜되냐???
	//std::random_shuffle(begin(arr), end(arr));

	//Cents들 끼리 크기 비교를 못함
	std::sort(arr.begin(), arr.end());

	for (auto& e : arr)
		cout << e << " ";
	cout << endl;

	
	//증감연산자
	cout << ++cents1 << endl;;
	cout << cents1++ << endl;;
	cout << cents1 << endl;;

	

}

