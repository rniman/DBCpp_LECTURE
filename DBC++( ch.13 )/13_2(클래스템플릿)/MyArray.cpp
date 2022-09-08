#include "MyArray.h"

template<typename T, unsigned int T_size>
void MyArray<T,T_size>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

//explicit instantiation -> T_size가 있으면 사용할 수 없다
//헤더파일에 넣는게 좋음
template class MyArray<char>;
template class MyArray<int>;
template class MyArray<double>;

//template void MyArray<char>::print();
//template void MyArray<int>::print();
//template void MyArray<double>::print();