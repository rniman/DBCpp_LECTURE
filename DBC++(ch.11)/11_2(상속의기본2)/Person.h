#pragma once

#include <string>
#include <iostream>

class Person
{
private:
	std::string m_name;

public:
	Person(const std::string& name_in = "Empty Name")
		:m_name(name_in)
	{

	}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName() const
	{
		return  m_name;
	}

	void doNothing() const
	{
		std::cout << m_name << " is doing nothing" << std::endl;
	}

	//friend std::ostream& operator << (std::ostream& out, const Person& person)
	//{
	//	out << person.m_name;
	//	return out;
	//}

};