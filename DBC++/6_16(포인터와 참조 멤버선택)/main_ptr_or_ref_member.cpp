#include <iostream>

using namespace std;


struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 10;
	person.weight = 45.5;

	Person& ref = person;
	ref.age = 15;
	
	Person* ptr = &person;
	ptr->age = 13;
	(*ptr).age = 15;

	Person& ref2 = *ptr;
	ref2.age = 10;

	return 0;
}