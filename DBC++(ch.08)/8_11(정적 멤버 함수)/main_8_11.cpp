#include <iostream>
using namespace std;

class Something
{
public:

	//이너 클래스
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	
	//static 멤버 변수는 이곳에서 초기화 시켜 줄 수 없음 
	//클래스 안에서 초기화 하기위해서 이너 클래스를 이용해야함
	Something()
		:m_value(123)/*, s_value(100)*/
	{}

	static int getValue()
	{
		//static 멤버 함수는 this-> 를 사용 할 수 없음
		//m_value 또한 this->m_value이므로 사용 불가능
		
		return s_value;
	}

	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;
//s_initializer생성자가 생성되면서 s_value를 초기화 해줌
Something::_init Something::s_initializer;


int main()
{
	//s_value 접근 불가능 -> 멤버 함수를 static으로 선언
	cout << Something::getValue() << endl;
	Something s1;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;


	//class내에서 멤버 함수는 어느 객체든 주소가 같음
	int (Something:: * fptr1)() = &Something::temp;

	cout << (s1.*fptr1)() << endl;

	//static 멤버 함수
	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;


	return 0;
}