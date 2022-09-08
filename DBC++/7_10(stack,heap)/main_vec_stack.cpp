#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int>& stack)
{
	for (auto& e : stack)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// int *v = new int[3]{1,2,3};
	std::vector<int> v{ 1,2,3 };

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	v.resize(10);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	//메모리를 줄일때 속도를 높이기 위해서 없는척한다
	v.resize(2);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	
	//억지로 3번째 값을 가져옴
	int* ptr = v.data();
	cout << endl;
	cout << ptr[2] << endl;
	cout << endl;
	//메모리 용량을 미리 확보해둠
	v.reserve(1024);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	//스택
	cout << endl << "스택처럼 사용하기 " << endl;
	std::vector<int> stack;
	
	stack.push_back(3);
	printStack(stack);
	stack.push_back(5);
	printStack(stack);
	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);
	
	stack.pop_back();
	printStack(stack);


	return 0;
}