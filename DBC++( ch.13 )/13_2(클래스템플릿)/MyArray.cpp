#include "MyArray.h"

template<typename T, unsigned int T_size>
void MyArray<T,T_size>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation -> T_size�� ������ ����� �� ����
//������Ͽ� �ִ°� ����
template class MyArray<char>;
template class MyArray<int>;
template class MyArray<double>;

//template void MyArray<char>::print();
//template void MyArray<int>::print();
//template void MyArray<double>::print();