#include <iostream>


int getResult()
{

	return 100*100;
}

void doSomething(int& lref)
{
	std::cout << "L-value ref" << std::endl;
}

void doSomething(int&& rref)
{
	std::cout << "R-value ref" << std::endl;
}

int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	//L-value reference *주석처리한 것은 사용 불가능*

	int& lr1 = x;		//Modifiable l-value
	//int& lr2 = cx;	//Non-Modifiable l-value
	//int& lr3 = 5;		//R-value

	const int& lr4 = x;		//Modifiable l-value
	const int& lr5 = cx;	//Non-Modifiable l-value
	const int& lr6 = 5;		//R-value

	//R-value reference
	
	//int&& rr1 = x;		//Modifiable l-value
	//int&& rr2 = cx;		//Non-Modifiable l-value
	int&& rr3 = 5;			//R-value
	int&& rrr = getResult();

	//const int&& rr4 = x;		//Modifiable l-value
	//cosnt int&& rr5 = cx;		//Non-Modifiable l-value
	const int&& rr6 = 5;			//R-value

	// L/R-value reference parameters
	doSomething(x);
	//doSomething(cx);
	doSomething(5);
	doSomething(getResult());

	return 0;
}