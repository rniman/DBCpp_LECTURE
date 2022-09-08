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

	//�޸𸮸� ���϶� �ӵ��� ���̱� ���ؼ� ����ô�Ѵ�
	v.resize(2);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	
	//������ 3��° ���� ������
	int* ptr = v.data();
	cout << endl;
	cout << ptr[2] << endl;
	cout << endl;
	//�޸� �뷮�� �̸� Ȯ���ص�
	v.reserve(1024);

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	//����
	cout << endl << "����ó�� ����ϱ� " << endl;
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