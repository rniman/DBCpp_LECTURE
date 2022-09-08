
#include "Lecture.h"

int main()
{
	using namespace std;

	//동적할당으로도 선언할수도 있음
	//분산처리할때는 이러한 방식이 안됨
	Student* ptr_std1 = new Student("PTR_Shin", 0);
	Student std1("Shin", 0);
	Student std2("Kim", 2);
	Student std3("Suk", 0);

	Teacher prof1("Hong");
	Teacher prof2("Park");

	//Composition Relationship -> 같은 이름을 가진 학생이 lec1 lec2에서 따로 놈
	//Lecture lec1("Introduction to Computer Programming");
	//lec1.assignTeacher(Teacher("Prof.Hong"));
	//lec1.registerStudent(Student("Shin", 0));
	//lec1.registerStudent(Student("Kim", 2));
	//lec1.registerStudent(Student("Suk", 1));

	//Lecture lec2("Computational Thinking");
	//lec2.assignTeacher(Teacher("Prof.Park"));
	//lec2.registerStudent(Student("Shin", 0));

	


	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(&prof1);
	lec1.registerStudent(&std1);
	lec1.registerStudent(&std2);
	lec1.registerStudent(&std3);
	lec1.registerStudent(ptr_std1);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(&prof2);
	lec2.registerStudent(&std1);
	lec2.registerStudent(ptr_std1);

	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	delete ptr_std1;
}