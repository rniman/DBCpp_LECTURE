#include "MyArray.h"

int main()
{
	//Ŭ�������� ����� �ڷ����� ǥ���ؾ���
	MyArray<double> my_array(10);

	for (int i = 0; i < my_array.getLength(); ++i)
		my_array[i] = i * 0.1;

	my_array.print();

	return 0;
}