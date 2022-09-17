#include <iostream>

//typename 대신 class 사용가능 
//기능은 거의 비슷
template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


int main()
{
	std::cout << getMax(1.0, 3.0) << ' ' << getMax(15u, 4u) << ' ' << getMax(5.9f, 3.3f) << std::endl;

	return 0;
}