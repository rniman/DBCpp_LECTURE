#include <iostream>

using namespace std;

int getInt()
{

	while (true)
	{
		cout << "int number : ";
		int x;
		cin >> x;
	
		if (std::cin.fail())
		{
			//�ٽ� �Է� ���״� ��Ʈ �÷��׸� �ʱ�ȭ ��Ŵ
			std::cin.clear();

			//���۸� ���
			std::cin.ignore(32767, '\n');
			cout << "Invalid num" << endl;

		}
		else
		{
			std::cin.ignore(32767, '\n');
			return x;
		}

	}
}

char getOperator()
{
	while (true)
	{
		cout << "operator : ";
		char op;
		cin >> op;
		

		if (op == '+' || op == '-')
			return op;
		else
			cout << "Invalid operator" << endl;
	}
}

void printResult(int x, char op, int y)
{
	if (op == '+')cout << x + y << endl;
	else if (op == '-')cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();
	printResult(x, op, y);

	return 0;
}