#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override//noexcept 붙여야한다
	{
		return "Custom exception";
	}
};

int main()
{
	try
	{
		std::string s;
		s.resize(-1);

		//throw std::runtime_error("Bad thing happend");
		//throw CustomException();
	}
	catch (std::exception& exception)
	{
		//exception class의 자식클래스를 알수있다
		std::cout << typeid(exception).name() << endl;
		//예외 내용이 뭔지 알수있다.
		std::cerr << exception.what() << endl;
	}

	return 0;
}