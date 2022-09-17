#pragma once
#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;

	//Teacher teacher;
	//std::vector<Student> students;
	
	//�ּҸ� �޾ƿ�
	Teacher *teacher;
	std::vector<Student*> students;


public:
	Lecture(const std::string& name_in)
		:m_name(name_in)
	{}

	~Lecture()
	{


	}

	//void assignTeacher(const Teacher& const teacher_input)
	//{
	//	teacher = teacher_input;
	//}

	//void registerStudent(const Student& const student_input)
	//{
	//	students.push_back(student_input);
	//}

	//Teacher* const teacher_input �����͸� �ٲܼ� ����
	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent(Student* const student_input)
	{
		*student_input = Student("HHH", 1999);
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << m_name << " Study" << '\n' << '\n';

		//&�� ������ ���� ������Ʈ�� �ȵ�
		//for (auto& element : students)
		//	element.setIntel(element.getIntel() + 1);
		
		//&�� �־ �۵���
		for (auto &element : students)
			element->setIntel(element->getIntel() + 1);

	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture Name: " << lecture.m_name << '\n';

		out << *lecture.teacher << '\n';
		//for (auto element : lecture.students)
		//	out << element << '\n';
		for (auto element : lecture.students)
			out << *element << '\n';
		return out;

	}




};
