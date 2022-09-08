#include <iostream>
#include <string>
using namespace std;


//인터페이스 클래스: 내부의 모든 함수들이 
//pure virtual function일 경우를 뜻함
//클래스자체는 성능을 가지지않음 -> 상속구조를 도와주는 문법
class IErrorLog
{
public:
	virtual bool reportError(const char* errMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog :public IErrorLog
{
public:
	virtual bool reportError(const char* errMessage) override
	{
		cout << "file Error" << endl;
		return true;
	}


};

class ConsoleErrorLog :public IErrorLog
{
	virtual bool reportError(const char* errMessage) override
	{
		cout << "console Error" << endl;
		return true;
	}


};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!");
}

int main()
{
	FileErrorLog file;
	ConsoleErrorLog E_console;

	doSomething(file);
	doSomething(E_console);


	return 0;
}