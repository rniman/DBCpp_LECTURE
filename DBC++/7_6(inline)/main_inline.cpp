#include <iostream>

using namespace std;

//함수가 아닌것처럼 됨
//inline을 쓰도록 권유 -> 강제하지 않음
//최근에는 inline을 쓰는게 의미가 있을지 의문이 있음
inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;
	
	//inline 함수와 같음
	cout << (5 > 6 ? 6 : 5) << endl;

	return 0;
}