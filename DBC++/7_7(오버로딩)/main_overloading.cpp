#include <iostream>
#include <string>

int add(int x, int y)
{
	return x + y;
}

//double add(int x,int y) ->���� Ÿ�Ը� �ٸ��� �����ε� �� �� ����


double add(double x, double y)
{
	return x + y;
}

void getRandomValue(int &x)
{

}

void getRandomValue(double& x)
{

}

void print(const char* value) {}
void print(unsigned int value) {}
void print(float value) {}

int main()
{
	using namespace std;

	add(1 , 2);
	add(1.0, 2.1);

	print(0u);
	print((unsigned int)'a');
	print("a");

}