#include <iostream>
using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input)
		:m_value(input)
	{}

	void print()
	{
		cout << m_value << endl;
	}
};

//포인터에 대해 구체화
template<class T>
class A<T*>
{
private:
	T* m_value;

public:
	A(T* input)
		:m_value(input)
	{}

	void print()
	{
		cout << *m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	a_int.print();

	int temp = 456;
	A<int*> a_ptr_int(&temp);

	//당연히 주소가 출력됨
	//포인터에 대한 구체화를 해버림
	a_ptr_int.print();

	double temp_d = 3.14;
	A<double*> a_ptr_double(&temp_d);
	a_ptr_double.print();

	return 0;
}