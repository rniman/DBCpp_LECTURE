#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodBye(const string& s)
{
	cout << "Good Bye " << s << endl;
}

class Object
{
public:
	void hello(const string& s)
	{
		cout << "hello " << s << endl;
	}

};

int main()
{
	//-> void 리턴 타입을 뒤에 붙힌 것
	//아래는 function pointer처럼 사용한 것
	auto func = [](const int& i) -> void {cout << "Hello, World" << endl; };

	func(123);

	[](const int& i) -> void {cout << "Hello, World" << endl; }(1234);

	{
		//[&]
		//&를 사용하면 밖에서 레퍼런스로 변수를 가져옴
		//=을 사용하면 copy를 함
		//[&name]으로 사용해도됨
		string name = "shin";
		[&]() {std::cout << name << endl; }();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	
	auto func2 = [](int val) {cout << val << endl; };
	
	//algorithm에 있음
	for_each(v.begin(), v.end(), func2);

	//위의 방식보다 아래방식이 더 많이 쓰임
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []()->int {return 1000; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	//int 파라미터를 넣기 귀찮음 -> bind 사용
	std::function<void()>func4 = std::bind(func3, 234);
	func4();

	//place holder를 알아야함
	//bind를 사용할 시 인자를 대체하기 위해서 사용
	// 함수가 인자를 2개를 받을때 std::bind(함수 이름, std::placeholders::_1, 1);을 하면 
	//placeholders::_1을 사용한 인자값만 넣으주게 되면 작동시킬수 있다. 1은 고정적으로 인자를 받음!
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f("world");

		auto f2 = std::bind(&goodBye, std::placeholders::_1);

		f2("world");
	}

	return 0;
}



