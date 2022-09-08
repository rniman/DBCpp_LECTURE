#pragma once
#include <iostream>

//헤더파일에는 using namespace 사용 자제

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(int value);
	Calc& sub(int value);
	Calc& mult(int value);
	void print();
};