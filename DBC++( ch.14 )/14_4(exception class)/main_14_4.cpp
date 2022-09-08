#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override//noexcept �ٿ����Ѵ�
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
		//exception class�� �ڽ�Ŭ������ �˼��ִ�
		std::cout << typeid(exception).name() << endl;
		//���� ������ ���� �˼��ִ�.
		std::cerr << exception.what() << endl;
	}

	return 0;
}