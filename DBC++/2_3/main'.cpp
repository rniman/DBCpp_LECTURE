#include <iostream> //<cstdint> 포함되있음

int main()
{
	using namespace std;

	int16_t i(5);
	int8_t myint = 65;

	cout << i << endl;

	int_fast8_t fi(5);	//가장 빠른  1바이트 데이터 타입
	int_least64_t fl(5);//적어도 8바이트

}