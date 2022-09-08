#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print()
	{
		cout << "Base" << endl;
	}
};

class Derived :public Base
{
public:
	int m_j = 0;

	virtual void print()
	{
		cout << "Derived" << endl;
	}
};

void doSomething(Base& b)
{
	b.print();
}

int main()
{
	
	Derived d;
	//&가 없어지면 다형성이 없어짐 -> 상속 내용을 못담음
	Base& b = d;
	Base c;

	b.print();

	doSomething(d);
	doSomething(b);

	std::vector<Base*> my_vec;
	my_vec.push_back(&c);
	//Base에 의해 객체가 잘림 -> 포인터로 바꿔줌
	my_vec.push_back(&d);

	for (auto& ele : my_vec)
		ele->print();

	//레퍼런스를 사용하고 싶다면 다음과 같이하여야한다
	std::vector<std::reference_wrapper<Base>> my_vec2;
	my_vec2.push_back(c);
	my_vec2.push_back(d);

	//get()을 통해 가져옴
	for (auto& ele : my_vec2)
		ele.get().print();
}