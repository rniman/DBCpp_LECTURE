#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	

	void* ptr = nullptr;

	// void 포인터에 넣으면 무슨 자료형인지 알수는 없음
	// void 포인터는 연산을 할 수 없음  ex) ptr + 1
	ptr = &i;
	ptr = &f;
	

	cout << &f << " " << ptr;

	//디 레퍼러싱 불가능
	//강제로 캐스팅
	/*cout << *ptr << endl;*/
	cout << *static_cast<float*>(ptr) << endl;

	//다형성을 구현하다 보면 써야할때가 생겨버림 -> 최근에는 좋아짐

	return 0;
}