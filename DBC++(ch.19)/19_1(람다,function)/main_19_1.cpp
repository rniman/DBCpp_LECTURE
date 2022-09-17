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
	//-> void ���� Ÿ���� �ڿ� ���� ��
	//�Ʒ��� function pointeró�� ����� ��
	auto func = [](const int& i) -> void {cout << "Hello, World" << endl; };

	func(123);

	[](const int& i) -> void {cout << "Hello, World" << endl; }(1234);

	{
		//[&]
		//&�� ����ϸ� �ۿ��� ���۷����� ������ ������
		//=�� ����ϸ� copy�� ��
		//[&name]���� ����ص���
		string name = "shin";
		[&]() {std::cout << name << endl; }();
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	
	auto func2 = [](int val) {cout << val << endl; };
	
	//algorithm�� ����
	for_each(v.begin(), v.end(), func2);

	//���� ��ĺ��� �Ʒ������ �� ���� ����
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	cout << []()->int {return 1000; }() << endl;

	std::function<void(int)> func3 = func2;
	func3(123);

	//int �Ķ���͸� �ֱ� ������ -> bind ���
	std::function<void()>func4 = std::bind(func3, 234);
	func4();

	//place holder�� �˾ƾ���
	//bind�� ����� �� ���ڸ� ��ü�ϱ� ���ؼ� ���
	// �Լ��� ���ڸ� 2���� ������ std::bind(�Լ� �̸�, std::placeholders::_1, 1);�� �ϸ� 
	//placeholders::_1�� ����� ���ڰ��� �����ְ� �Ǹ� �۵���ų�� �ִ�. 1�� ���������� ���ڸ� ����!
	{
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		f("world");

		auto f2 = std::bind(&goodBye, std::placeholders::_1);

		f2("world");
	}

	return 0;
}



