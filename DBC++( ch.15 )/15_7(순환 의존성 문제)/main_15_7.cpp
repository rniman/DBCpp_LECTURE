#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person
{ 
	string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner;

public:
	Person(const std::string& name)
		:m_name(name)
	{
		cout << m_name << " constructed" << endl;
	}

	~Person()
	{
		cout << m_name << " destroyed" << endl;
	}

	friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << p1->m_name << ' ' << p2->m_name << " partner" << endl;

		return true;
	}

	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const string& getName() const
	{
		return this->m_name;
	}
};


int main()
{
	auto A = make_shared<Person>("A");
	auto B = make_shared<Person>("B");

	//메모리 누수가 발생 -> weak_ptr 사용
	//weak_ptr의 단점 -> lock을 해줘야함
	partnerUp(A, B);

	cout << A->getPartner()->getName() << endl;

	return 0;
}