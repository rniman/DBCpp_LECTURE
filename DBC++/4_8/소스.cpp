#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
	using namespace std;

	//enum class

	enum class Color
	{
		RED,
		BLUE,
	};

	enum class Fruit
	{
		BANANA,
		APPLE,
	};

	Color color = Color::RED;
	Fruit fruit = Fruit::BANANA;

	
	//자료형에 가명 붙여주기

	std::int8_t i(97);

	typedef double distance_t;

	double my_distance;
	distance_t homeWork;

	//typedef std::vector< std::pair <std::string, int > > pairlist;
	using pairlist = std::vector< std::pair <std::string, int > >;

	std::vector< std::pair <std::string, int > > pairlist;
	pairlist pairlist_S;

	return 0;
}