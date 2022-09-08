#include "Resource.h"
#include "AutoPtr.h"
#include <memory>

using namespace std;

//RAII:resource a acquisition is initialization


void doSomthing()
{
	//dull ptr
	Resource* res = new Resource;

	//auto_ptr -> �ֱ� ���������� ������� ����
	//AutoPtr<Resource> res_auto = new Resource;
	AutoPtr<Resource> res_auto(new Resource);
	AutoPtr<Resource> res2_auto;

	cout << res_auto.m_ptr << endl;
	cout << res2_auto.m_ptr << endl;

	//�Ŀ� �Ҹ��ڽ���� �̹� ����Ʈ�� �����Ѱ��� �ѹ��� ����Ʈ�� �õ���
	//������ �ϳ��� ������ �ϴ°��� ���� -> ������ ����
	//move semantics	
	res2_auto = res_auto;

	//systax vs semantics
	//������ �³� vs �������� �ǹ̰� ����



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
