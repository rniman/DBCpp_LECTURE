#include <iostream>
#include <string>

int add(int x, int y)
{
	return x + y;
}

//double add(int x,int y) ->리턴 타입만 다르면 오버로딩 할 수 없음


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