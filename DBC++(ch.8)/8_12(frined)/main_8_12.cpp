#include <iostream>
using namespace std;

//전방 선언
class A;

class B
{
private:
	int m_value = 2;

public:
	friend void doSomething(A& a, B& b);
	
	//함수 정의를 뒤로 옮김
	void printfA(A& a);
	
};

class A 
{
private:
	int m_value = 1;

	//class B의 존재를 알 수 없음 -> 전방 선언
	friend void doSomething(A& a, B& b);
	
	//B에서 A를 접근 가능
	//friend class B;
	//printA()만 접근 가능
	friend void B::printfA(A& a);
};

void B::printfA(A& a)
{
	cout << a.m_value << endl;
}


void doSomething(A& a,B& b)
{
	//private 멤버 변수에 접근못함
	//friend 선언
	cout << a.m_value <<" "<<b.m_value << endl;
}

int main()
{
	A a;
	B b;
	b.printfA(a);
	
	return 0;
}