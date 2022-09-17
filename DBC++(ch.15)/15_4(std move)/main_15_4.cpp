#include "AutoPtr.h"
#include "Resource.h"
#include <vector>
#include <string>
using namespace std;

template<class T>
void MySwap(T& a,T& b)
{
	//copy
	/*T tmp = a;
	a = b;
	b = tmp;*/

	//move
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);

}

int main()
{
	{
		AutoPtr<Resource> res1(new Resource(1000000000));

		cout << res1.m_ptr << endl;


		//AutoPtr<Resource> res2 = res1;
		
		//move를 사용하겠다
		AutoPtr<Resource> res2 = std::move(res1);

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}

	cout << endl;
	cout << endl;


	{
		AutoPtr<Resource> res3(new Resource(3));
		res3->setAll(3);
		

		AutoPtr<Resource> res4(new Resource(5));
		res4->setAll(5);

		res3->print();
		res4->print();

		MySwap(res3, res4);

		res3->print();
		res4->print();

	}

	cout << endl;
	cout << endl;

	{
		vector<string> v;
		string str = "hello";

		v.push_back(str);

		cout << str << endl;

		v.push_back(std::move(str));

		//str이 없어짐
		cout << str << endl;
		cout << v[0] << " " << v[1] << endl;

	}

	cout << endl;
	cout << endl;

	{
		string x{ "abc" };
		string y{ "df" };

		cout << x << endl;
		cout << y << endl;

		MySwap(x, y);

		cout << x << endl;
		cout << y << endl;

	}
}