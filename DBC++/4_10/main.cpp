#include <iostream>
#include <string>


struct Person
{
	double height = 0;
	float weight = 0;
	int age = 0;
	std::string name = "Empty";

	void PrintPerson()
	{
		std::cout << height << " " << weight << " " << age << " " << name << std::endl;
	}
};

struct Family
{
	Person me, mom, dad;
};

Person Mom_status()
{
	Person mom = { 1.6,40,45,"Kim" };
	return mom;
};

struct Employee
{
	short	id;		//2바이트가아닌 4바이트로 계산됨 ->padding
	int		age;
	double	wage;
};

int main()
{
	using namespace std;
	Person Me{ 2.0,100.0,20,"Shin" };
	Person Any;
	Any = Me;

	Me.PrintPerson();
	Any.PrintPerson();

	Family my_family;
	my_family.me = Me;
	my_family.me.PrintPerson();

	my_family.mom = Mom_status();
	my_family.mom.PrintPerson();


	Employee emp1;

	cout << sizeof(emp1) << endl;


	return 0;

}