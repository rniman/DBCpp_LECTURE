#include "Resource.h"
#include <memory>

using namespace std;

auto doSomething()
{
	auto res = std::make_unique<Resource>(5);
	return res;

	//return std::make_unique<Resource>(5);

	//return std::make_unique<Resource>(new Resource(5));
}

//move�� ����ؾ��ϴ� doSomething
//auto doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(10);
//	return res;
//}
void doSomething2(std::unique_ptr<Resource>& res)
{
	res->setAll(10);
}
void doSomething2(Resource* res)
{
	res->setAll(100);
}


int main()
{
	{
		//�⺻���� ����ũ ���̳�
		std::unique_ptr<Resource> res(new Resource(1000000));
	}

	cout << endl;
	cout << endl;

	{
		std::unique_ptr<int> upi(new int);

		//auto* ptr = new Resource(5);
		
		//std::unique_ptr<Resource> res1(new Resource(5));
		auto res1 = std::make_unique<Resource>(5);
		//auto res1 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;
		std::cout << std::boolalpha;
		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;

		//����ũ �����ʹ� ���縦 �� �� ����
		//res2 = res1;

		//move�� �����ϴ�
		res2 = std::move(res1);

		cout << static_cast<bool>(res1) << endl;
		cout << static_cast<bool>(res2) << endl;

		res1->print();
		res2->print();

	}

	cout << endl;
	cout << endl;

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		//move�� ��� -> �������� �ٽ� ����ϵ��� �ؾ���
		//res1 = doSomething2(std::move(res1));

		doSomething2(res1);
		res1->print();

		//parameter�� �����͸� ������
		doSomething2(res1.get());
		res1->print();

	}


	return 0;
}