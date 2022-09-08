#include <iostream>

using namespace std;

//const를 매개변수에 붙여주는 순간 함수내에서 값을 바꿀수 없음
//복사가 일어나지 않음
void doSomething(/*const*/ int &n)
{

	n = 10;
	cout << "in doSomething" << n << " " << &n << endl;
}

//const가 있으면 함수 호출시 변수가아닌 숫자도 매개변수로 사용이 가능함
void doSomething2(const int& x)
{
	cout << endl << "DoSomething2" << endl;
	cout << &x << endl;
	cout << x << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main()
{
	int value{ 5 };

	//pointer
	int* ptr = nullptr;
	ptr = &value;

	//reference -> 별명
	//1.반드시 초기화가 되어야하고 리터럴이 못들어감
	int& ref = value;


	cout << ref << endl;

	ref = 10;

	cout << value << endl;
	cout << ref << endl;

	cout << endl << "주소값\n";
	cout << &value << endl;
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;

	//const 변수에는 허용하지 않음 
	//const를 붙이면 가능
	/*const int y = 8;
	int& ref2 = y;*/
	const int y = 8;
	const int& ref2 = y;

	cout << endl;
	int value1 = 5;
	int value2 = 10;

	int &ref3 = value1;
	
	cout << ref3 << endl;
	
	//value1의 값을 같이 바꿔버림
	ref3 = value2; 

	cout << ref3 << endl;

	//함수에 레퍼런스 이용하기
	int n = 5;
	cout << endl << n << " " << &n << endl;
	doSomething(n);
	cout << n << endl;

	
	
	
	//타이핑이 힘들어짐
	Other ot;
	ot.st.v1 = 1.0;

	//레퍼런스를 이용해서 간략하게 사용가능
	float& v2 = ot.st.v2;
	v2 = 2.3;

	//포인터와 레퍼런스가 동일하게 작동
	int  value_0 = 5;
	int* const ptr_0 = &value_0;
	int& ref_0 = value_0;


	int x = 5;
	const int &ref_x = x;
	const int& ref_x2 = ref_x;

	
	const int& ref_num = 5 + 4;
	const int ref_num1 = 4 + 3;
	
	//매개변수에 const가 있으면 함수 호출시 변수가아닌 숫자도 매개변수로 사용이 가능함
	doSomething2(1000);
	
	return 0;
}