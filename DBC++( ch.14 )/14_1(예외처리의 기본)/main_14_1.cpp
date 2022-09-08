#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findFirstChar(const char* string, char ch)
{
	for (std::size_t index = 0; index < strlen(string); ++index)
		if (string[index] == ch)
			return index;

	//no match
	return -1;
}

double divide(int x, int y, bool& success)
{
	if (y == 0)
	{
		success = false;
		return 0.0;
	}

	success = true;
	return static_cast<double>(x) / y;
}

int main()
{

	//기존 c++ 방식
	bool success;
	double result = divide(5, 3, success);

	if (!success)
		std::cerr << "An error occurred" << std::endl;
	else
		std::cout << "Result is " << result << std::endl;

	std::ifstream input_file("temp.txt");
	if (!input_file)
		std::cerr << "Cannot open file" << endl << endl;

	//예외처리는 예측할수 없는 일이 많은경우 사용함 -> 퍼포먼스는 떨어짐
	//게임서버 인터넷서버 등등
	
	// 예외처리의 방식
	// try, catch, throw

	double x;
	cin >> x;
	 
	try
	{
		if (x < 0.0)throw std::string("Negative input");

		cout << std::sqrt(x) << endl;
	}
	catch (std::string error_message) //auto casting을 해주지않는다 ->형변환이 엄격하다
	{
		//do something to respond
		cout << error_message << endl;
	}

	try
	{
		if (x < 0.0)throw x;

		cout << std::sqrt(x) << endl;
	}
	catch (double error_message) //auto casting을 해주지않는다 ->형변환이 엄격하다! 
	{
		//do something to respond
		cout << error_message << endl;
	}

	return 0;
}