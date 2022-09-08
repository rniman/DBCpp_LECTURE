#pragma once

#include <string>
#include "Position2D.h"



class Monster
{
private:
	std::string m_name;

	//location�� monster�� �� �������(Composition)�̴�	
	Position2D m_location;
	//int m_x;
	//int m_y;

public:
	Monster(const std::string& name, const Position2D& location)
		:m_name(name), m_location(location)
	{

	}


	void moveTo(const Position2D& loc_target)
	{
		m_location.set(loc_target);
	}

	friend std::ostream& operator << (std::ostream& out, const Monster& mon)
	{
		out << mon.m_name << "\t" << mon.m_location;
		return out;
	}
};