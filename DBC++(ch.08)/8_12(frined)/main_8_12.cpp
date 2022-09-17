#include <iostream>
using namespace std;

//���� ����
class A;

class B
{
private:
	int m_value = 2;

public:
	friend void doSomething(A& a, B& b);
	
	//�Լ� ���Ǹ� �ڷ� �ű�
	void printfA(A& a);
	
};

class A 
{
private:
	int m_value = 1;

	//class B�� ���縦 �� �� ���� -> ���� ����
	friend void doSomething(A& a, B& b);
	
	//B���� A�� ���� ����
	//friend class B;
	//printA()�� ���� ����
	friend void B::printfA(A& a);
};

void B::printfA(A& a)
{
	cout << a.m_value << endl;
}


void doSomething(A& a,B& b)
{
	//private ��� ������ ���ٸ���
	//friend ����
	cout << a.m_value <<" "<<b.m_value << endl;
}

int main()
{
	A a;
	B b;
	b.printfA(a);
	
	return 0;
}