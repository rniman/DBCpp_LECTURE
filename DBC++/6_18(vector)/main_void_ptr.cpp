#include <iostream>

using namespace std;

int main()
{
	int i = 5;
	float f = 3.0;
	

	void* ptr = nullptr;

	// void �����Ϳ� ������ ���� �ڷ������� �˼��� ����
	// void �����ʹ� ������ �� �� ����  ex) ptr + 1
	ptr = &i;
	ptr = &f;
	

	cout << &f << " " << ptr;

	//�� ���۷��� �Ұ���
	//������ ĳ����
	/*cout << *ptr << endl;*/
	cout << *static_cast<float*>(ptr) << endl;

	//�������� �����ϴ� ���� ����Ҷ��� ���ܹ��� -> �ֱٿ��� ������

	return 0;
}