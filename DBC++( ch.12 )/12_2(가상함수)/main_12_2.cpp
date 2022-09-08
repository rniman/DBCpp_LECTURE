#include <iostream>

using namespace std;

class A
{
public:
	//가상함수 -> 상속받는 클래스들이 모두 영향을 받음
	virtual void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	//virtual이 없어도 되지만 써주는게 후에 편안함/
	//속도가 느리다는 단점이 있다
	//리턴타입만 바꾼 오버라이딩은 불가능
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

	//virtual 사용
	A& ref = b;
	ref.print();
	//A에만 virtual을 사용하면 제대로 작동함
	B& ref2 = d;
	ref2.print();

	return 0;
}