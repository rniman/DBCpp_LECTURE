#include <iostream>

//typename ��� class ��밡�� 
//����� ���� ���
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