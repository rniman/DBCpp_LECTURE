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
	//&�� �������� �������� ������ -> ��� ������ ������
	Base& b = d;
	Base c;

	b.print();

	doSomething(d);
	doSomething(b);

	std::vector<Base*> my_vec;
	my_vec.push_back(&c);
	//Base�� ���� ��ü�� �߸� -> �����ͷ� �ٲ���
	my_vec.push_back(&d);

	for (auto& ele : my_vec)
		ele->print();

	//���۷����� ����ϰ� �ʹٸ� ������ �����Ͽ����Ѵ�
	std::vector<std::reference_wrapper<Base>> my_vec2;
	my_vec2.push_back(c);
	my_vec2.push_back(d);

	//get()�� ���� ������
	for (auto& ele : my_vec2)
		ele.get().print();
}