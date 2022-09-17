#include <iostream>

using namespace std;

class A
{
public:
	//�����Լ� -> ��ӹ޴� Ŭ�������� ��� ������ ����
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	//virtual�� ��� ������ ���ִ°� �Ŀ� �����/
	//�ӵ��� �����ٴ� ������ �ִ�
	//����Ÿ�Ը� �ٲ� �������̵��� �Ұ���
	virtual void print() { cout << "B" << endl; }
};

class C : public B
{
public:
	virtual void print() { cout << "C" << endl; }
};

class D : public C
{
public:
	virtual void print() { cout << "D" << endl; }
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	d.print();

	cout << endl;

	//virtual ���
	A& ref = b;
	ref.print();
	//A���� virtual�� ����ϸ� ����� �۵���
	B& ref2 = d;
	ref2.print();

	return 0;
}