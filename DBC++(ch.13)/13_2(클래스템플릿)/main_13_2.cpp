#include "MyArray.h"

int main()
{
	//클래스옆에 사용할 자료형을 표시해야함
	MyArray<double> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 0.1;

	my_array.print();

	return 0;
}