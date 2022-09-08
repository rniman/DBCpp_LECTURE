#include "Resource.h"
#include "AutoPtr.h"
#include <memory>

using namespace std;

//RAII:resource a acquisition is initialization


void doSomthing()
{
	//dull ptr
	Resource* res = new Resource;

	//auto_ptr -> 최근 버전에서는 사용하지 않음
	//AutoPtr<Resource> res_auto = new Resource;
	AutoPtr<Resource> res_auto(new Resource);
	AutoPtr<Resource> res2_auto;

	cout << res_auto.m_ptr << endl;
	cout << res2_auto.m_ptr << endl;

	//후에 소멸자실행시 이미 딜리트를 실행한곳을 한번더 딜리트를 시도함
	//권한을 하나만 가지게 하는것이 좋다 -> 소유권 이전
	//move semantics	
	res2_auto = res_auto;

	//systax vs semantics
	//문법이 맞냐 vs 내부적인 의미가 뭐냐



	cout << res_auto.m_ptr << endl;
	cout << res2_auto.m_ptr << endl;

	//.....


	delete res;

	return;
}


int main()
{
	doSomthing();


	return 0;
}
