//������Ʈ �Ӽ� -> C/C++ -> ��� -> C++ ��� ǥ�� (17�̻����� �ؾߵ�)

#include <iostream>
#include <tuple>

using namespace std;


//���� tuple
tuple<int, int> my_func()
{
	return tuple<int, int>(123, 456);
}

//���� tuple
auto my_func2()
{
	//<int,int>��������
	return tuple(123, 456, 789);
}

int main()
{
	tuple<int, int> result = my_func();
	auto result2 = my_func2();
	
	//a b c�� ���� �־� ��
	auto [a, b, c] = my_func2();

	cout << get<0>(result) << " " << get<1>(result) << endl;
	cout << get<0>(result2) << " " << get<2>(result2) << endl;
	cout << a << " " << b << " " << c;

	return 0;
}