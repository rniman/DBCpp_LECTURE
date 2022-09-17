#include <iostream>

using namespace std;

class A
{
public:
	//final 사용시 이후의 상속클래스들이 해당 함수를 오버라이드를 할수없다
	//virtual void print(int x) final { cout << "A" << endl; 
	
	//vitual void print(int x) { cout << "A" << endl; }

	void print() { cout << "A" << endl; }
	virtual A* getThis() { return this; }
};

class B : public A
{
public:
	//오버라이드의 오류를 미리 잡아줄수있음
	//virtual void print(int x) override { cout << "B" << endl; }
	
	void print() { cout << "B" << endl; }
	//원래는 리턴형이 다른 오버라이딩이 불가능하지만 
	//상속받은 클래스이므로 가능하다
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

	//B가 나와야하지만 파라미터가 다르면 오버라이딩이 불가능하다 -> 오버로딩으로 판단
	//-> override사용하면 compile에러를 잡아줌

	A& ref = b;

	
	b.getThis()->print();
	ref.getThis()->print();

	return 0;
}