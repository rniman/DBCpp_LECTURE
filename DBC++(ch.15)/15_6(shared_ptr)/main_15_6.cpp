#include "Resource.h"
#include <memory>
using namespace std;

void tempFunction(std::unique_ptr<Resource> res)
{

}

int main()
{
	//위험함
	//tempFunction(std::unique_ptr<Resource>(new Resource(100000000)));
	//make를 이용해 만드는게 좋다
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

			//res를 받으면 ptr1이 ptr2가 주소를 공유했는지를 알수가없음
			//따라서 ptr2가 소멸자를 실행시켜버림
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