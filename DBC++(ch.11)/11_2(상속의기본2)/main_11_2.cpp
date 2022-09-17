#include "Student.h"
#include "Teacher.h"

using namespace std;


int main()
{
	Student std("Shin",19);
	std.setName("Shin MG");

	Teacher teacher("Mr.a");

	cout << std << endl;
	cout << teacher << endl;

	std.doNothing();
	teacher.doNothing();

	std.study();
	teacher.teach();

	Person person;
	person.setName("SANTA");
	cout << person.getName() << endl;
	

	return 0;
}