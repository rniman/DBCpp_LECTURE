#include <iostream>

using namespace std;

class A
{
public:
	//final ���� ������ ���Ŭ�������� �ش� �Լ��� �������̵带 �Ҽ�����
	//virtual void print(int x) final { cout << "A" << endl; 
	
	//vitual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }
	virtual A* getThis() { return this; }
};

class B : public A
{
public:
	//�������̵��� ������ �̸� ����ټ�����
	//virtual void print(int x) override { cout << "B" << endl; }
	
	void print() { cout << "B" << endl; }
	//������ �������� �ٸ� �������̵��� �Ұ��������� 
	//��ӹ��� Ŭ�����̹Ƿ� �����ϴ�
	virtual B* getThis() { return this; }

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
	B b;

	//B�� ���;������� �Ķ���Ͱ� �ٸ��� �������̵��� �Ұ����ϴ� -> �����ε����� �Ǵ�
	//-> override����ϸ� compile������ �����

	A& ref = b;

	
	b.getThis()->print();
	ref.getThis()->print();

	return 0;
}