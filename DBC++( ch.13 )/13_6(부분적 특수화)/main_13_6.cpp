#include <iostream>
using namespace std;

template <class T,int size>
class StaticArray
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[](int index)
	{
		return m_array[index];
	}

	//��� �Լ��� ��üȭ �ϱ�� ��ƴ�
	//����� �������̵� -> �������� ������
	void print()
	{
		for (int i = 0; i < size; ++i)
			cout << (*this)[i] << ' ';
		cout << endl;
	}
};


template <class T, int size>
class StaticArray_char :public StaticArray<T,size>
{
};

template <int size>
class StaticArray_char<char,size> :public StaticArray<char, size>
{
public:
	void print()
	{
		for (int i = 0; i < size; ++i)
			cout << (*this)[i];
		cout << endl;
	}
};

//Ŭ���� ����� ����ʹ�
template<typename T,int size>
void print(StaticArray<T, size>& array)
{

	for (int i = 0; i < size; ++i)
		cout << array[i] << ' ';

	cout << endl;
}

//char ������ ��üȭ��
template<int size>
void print(StaticArray<char, size>& array)
{

	for (int i = 0; i < size; ++i)
		cout << array[i];

	cout << endl;
}



int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	print(int4);
	int4.print();

	//char Ÿ���� ��ĭ�̾������� ������
	StaticArray<char, 2> char2;
	char2[0] = 'e';
	char2[1] = 'a';

	print(char2);
	char2.print();

	StaticArray_char<char, 3> char3;
	char3[0] = 'e';
	char3[1] = 'a';
	char3[2] = 'a';

	char3.print();


	return 0;
}