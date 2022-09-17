#include <iostream>
#include <string>
using namespace std;


//�������̽� Ŭ����: ������ ��� �Լ����� 
//pure virtual function�� ��츦 ����
//Ŭ������ü�� ������ ���������� -> ��ӱ����� �����ִ� ����
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