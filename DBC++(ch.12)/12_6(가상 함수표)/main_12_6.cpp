#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func1() {};
	virtual void func2() {};
};

class Der :public Base
{
public:
	virtual void func1() {};
	virtual void func3() {};
};

int main()
{
	//virtual이 있을때 크기 8 없을때 1
	cout << sizeof(Base) << "  " << sizeof(Der) <<endl;

	return 0;
}