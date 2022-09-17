#include "Resource.h"
#include <memory>
using namespace std;

void tempFunction(std::unique_ptr<Resource> res)
{

}

int main()
{
	//������
	//tempFunction(std::unique_ptr<Resource>(new Resource(100000000)));
	//make�� �̿��� ����°� ����
	tempFunction(std::make_unique<Resource>(10000));

	Resource* res = new Resource(3);
	res->setAll(5);

	{
		auto ptr_shared = std::make_shared<Resource>(5);

		std::shared_ptr<Resource> ptr1(res);


		ptr_shared->setAll(7);
		ptr_shared->print();

		ptr1->print();

		{
		
			auto ptr_shared2 = ptr_shared;

			std::shared_ptr<Resource> ptr2(ptr1);

			//res�� ������ ptr1�� ptr2�� �ּҸ� �����ߴ����� �˼�������
			//���� ptr2�� �Ҹ��ڸ� ������ѹ���
			//std::shared_ptr<Resource> ptr2(res);

			ptr_shared2->setAll(10);
			ptr_shared2->print();

			ptr2->setAll(3);
			ptr2->print();

			cout << "Out Block" << endl;

		}

		ptr_shared->print();

		ptr1->print();

		cout << "Out Block" << endl; 
	
	}

	return 0;
}