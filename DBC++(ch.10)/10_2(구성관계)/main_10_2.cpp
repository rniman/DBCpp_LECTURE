#include <iostream>
#include "Monster.h"

using namespace std;

//1.구성관계

int main()
{
	Monster mon1("Sanson", Position2D(0, 0));
	Monster mon2("Ten", Position2D(0, 0));

	cout << mon1 << endl;

	//loop
	{
		//event
		mon1.moveTo(Position2D(1, 3));
		cout << mon1 << endl;

	}

	return 0;
}