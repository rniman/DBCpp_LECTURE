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

	//내부에 템플릿
	template<typename TT>
	void doSomething(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
	}

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
	a_int.doSomething<float>(1.33);
	a_int.doSomething(1.33);
	a_int.doSomething('1');

	return 0;
}