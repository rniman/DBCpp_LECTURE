#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Example
{
public:

	void ex1()
	{
		std::vector<int> vec;

		//초기 이터레이터
		for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
			cout << *itr;
		//auto등장 이터레이터
		for(auto itr = vec.begin();itr != vec.end();++itr)
			cout << *itr;
		//요즘 이터레이터
		for(auto itr:vec)
			cout << itr;

	}

	void ex2()
	{
		int x = int();
		//int
		auto auto_x = x;

		const int& crx = x;
		//int -> auto는 추론할때 const와 &를 때어버림
		auto auto_crx = crx;
		//const int&
		const auto& auto_crx2 = crx;
		//volatile -> 값이 자주 바뀌므로 최적화할때 빼달라는 의미
		volatile int vx = 1024;
		//auto는 volatile도 때어 버림
		auto avx = vx;

		volatile auto vavx = vx;
	}

	//template<class T>
	//void func_ex3(T arg)
	//{}

	//const &를 적어줌
	template<class T>
	void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int& crx = 123;
		
		//template에서 const int&에서 int만 파라미터로 들어감
		//-> 따로 명시 해줘야함
		func_ex3(crx);
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c;
		//rc = 123; -> error 레퍼런스로 가져올때 const 변수였다면 auto도 const를 추가함
	}

	void ex5()
	{
		int i = 42;
		auto&& ri_1 = i;	//l-value를 받아서 레퍼런스로 바뀜
		auto&& ri_2 = 42;
	}

	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;
		//*p2 = 43; -> error
	}

	//auto가 반드시 필요한 경우
	template<typename T,typename S>
	void func_ex7(T lhs, S rhs)
	{
		//곱하기의 값이 어떤 형태인지 알기 어려움 -> auto를 사용해서 해결
		auto prod1 = lhs * rhs;

		//typedef typeof(lhs* rhs) product_type; //c++ 11이전
		typedef decltype(lhs* rhs) product_type; //decltype 선언이 된 타입 


		product_type prod2 = lhs * rhs; 

		decltype(lhs * rhs)prod3 = lhs * rhs;
	}

	template<typename T, typename S>
	//decltype(lhs * rhs)  func_ex8(T lhs, S rhs)  -> 사용 불가능
	auto func_ex8(T lhs, S rhs) ->decltype(lhs * rhs)
	{
		return lhs * rhs;
	}

	//반환값 자료형 확인해보기
	void ex7_8()
	{
		func_ex7(1.0, 345);
		func_ex8(1.2, 345);
		cout << typeid(func_ex7(1.0, 345)).name() << endl;
		cout << typeid(func_ex8(1.2, 345)).name() << endl;
	}

	struct S
	{
		int m_x;
		S()
		{
			m_x = 42;
		}
	};

	void ex9()
	{
		int x;
		const int cx = 42;
		const int& crx = x;
		const S* p = new S();

		auto a = x;
		auto b = cx;
		auto c = crx;
		auto d = p;
		auto e = p->m_x;

		//decltype은 auto와 다르게 const와 레퍼런스를 가져옴
		typedef decltype(x)		 x_type;
		typedef decltype(cx)	 cx_type;
		typedef decltype(crx)	 crx_type;
		typedef decltype(p->m_x) m_x_type; //int m_x는 const가 선언이 안되서 그냥 int만 가져옴

		//괄호를 하나 더 넣어주면 레퍼런스가 붙음
		typedef decltype((x))		r_x_type;
		typedef decltype((cx))		r_cx_type;
		typedef decltype((crx))		r_crx_type;
		typedef decltype((p->m_x))	r_m_x_type; //레퍼런스가 붙음과 동시에 const가 붙음
	}

	const S foo()
	{
		return S();
	}

	const int& foobar()
	{
		return 123;
	}

	void ex10() 
	{
		std::vector<int> vec = { 42,43 };
		
		auto a = foo();
		typedef decltype(foo()) foo_type; //const 유지

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;//const int& 유지

		auto itr = vec.begin();
		typedef decltype(vec.begin()) itr_type;

		auto first_element = vec[0];
		decltype(vec[1]) second_element = vec[1];// vec[1]이 int&를 리턴해서 유지됨
	}

	void ex11()
	{
		int x = 0;
		int y = 0;
		const int cx = 42;
		const int cy = 43;
		double d1 = 3.14;
		double d2 = 2.72;

		typedef decltype(x* y)	prod_xy_type;
		auto a = x * y;

		typedef decltype(cx* cy) prod_cxcy_type; //result is pr-value
		auto b = cx * cy;

		typedef decltype(d1 < d2 ? d1 : d2) cond_type; //result is l-value -> add &
		auto c = d1 < d2 ? d1 : d2;

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; //int가 double로 promotion
		auto d = x < d2 ? x : d2;

		//auto d= std::min(x,dbl); -> error 두 파라미터의 자료형이 다르면 error가 남
	}

	//T와 S의 자료형이 같으면 리턴시 레퍼런스를 추가함 -> 문제가 될수 있음
	template<typename T,typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	//레퍼런스를 제거된 타입을 사용한다
	template<typename T, typename S>
	auto fpmin(T x, S y) -> typename std::remove_reference<decltype(x < y ? x : y)>::type
	{
		return x < y ? x : y;
	}

	void ex12()
	{
		int i = 42;
		double d = 45.1;
		//auto a = std::(i,d)
		auto a = std::min(static_cast<double>(i), d);

		int& j = i;
		typedef decltype(fpmin_wrong(d, d)) fpmin_type1;//레퍼런스 추가
		typedef decltype(fpmin_wrong(i, d)) fpmin_type2;
		typedef decltype(fpmin_wrong(j, d)) fpmin_type3;
		typedef decltype(fpmin_wrong(i, i)) fpmin_type4;
	}

	void ex13()
	{
		std::vector<int> vec;
		typedef decltype(vec[0]) integer;
	}

	template<typename R>
	class SomeFunctor
	{
	public:
		typedef R result_type;

		SomeFunctor()
		{}

		result_type operator() ()
		{
			return R();
		}
	};

	void ex14()
	{
		SomeFunctor<int> func;
		typedef decltype(func)::result_type integer;
	}

	void ex15()
	{
		auto lambda = []() {return 42; };
		decltype(lambda) lambda2(lambda);
		decltype((lambda)) lambda3(lambda);

		cout << &lambda << " " << &lambda2 << " " << &lambda3 << endl;
	}

	void ex16()
	{
		//generic lambda
		//람다는 파라미터에 auto사용 가능
		auto lambda = [](auto x, auto y)
		{
			return x + y;
		};

		cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;
	}
};


int main()
{

	Example ex;
	
	ex.ex7_8();
	
	ex.ex15();
	ex.ex16();
	
	return 0;

}
