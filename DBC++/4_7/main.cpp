#include <iostream>


enum Color
{
	Color_Black = -3,
	Color_Red,
	Color_Blue = 2,
	Color_Green = 2,
	Color_White,

};

int main()
{
	using namespace std;

	Color paint = Color_Black;
	Color next_paint = Color_Red;
	cout << paint << " " << next_paint << endl;
	cout << Color_White << endl;


	return 0;
}