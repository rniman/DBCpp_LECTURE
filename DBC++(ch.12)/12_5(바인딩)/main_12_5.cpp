#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int main()
{
	//정적바인딩

	int x, y;
	cin >> x >> y;

	int op;
	cout << "0:add , 1: subtract, 2:multiply" << endl;
	cin >> op;

	/*int result;
	switch (op)
	{
	case 0:
		result = add(x, y);
		break;
	case 1:
		result = subtract(x, y);
		break;
	case 2:
		result = multiply(x, y);
		break;
	default:
		break;
	}
	cout << result << endl;	 */

	//동정 바인딩
	//Dynamic(late) binding
	int(*func_ptr)(int, int) = nullptr;

	switch (op)
	{
	case 0:
		func_ptr = add;
		break;
	case 1:
		func_ptr = subtract;
		break;
	case 2:
		func_ptr = multiply;
		break;
	default:
		break;
	}

	cout << func_ptr(x, y) << endl;

	return 0;
}