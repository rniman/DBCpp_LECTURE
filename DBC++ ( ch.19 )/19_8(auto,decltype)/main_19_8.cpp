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

		//�ʱ� ���ͷ�����
		for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
			cout << *itr;
		//auto���� ���ͷ�����
		for(auto itr = vec.begin();itr != vec.end();++itr)
			cout << *itr;
		//���� ���ͷ�����
		for(auto itr:vec)
			cout << itr;

	}

	void ex2()
	{
		int x = int();
		//int
		auto auto_x = x;

		const int& crx = x;
		//int -> auto�� �߷��Ҷ� const�� &�� �������
		auto auto_crx = crx;
		//const int&
		const auto& auto_crx2 = crx;
		//volatile -> ���� ���� �ٲ�Ƿ� ����ȭ�Ҷ� ���޶�� �ǹ�
		volatile int vx = 1024;
		//auto�� volatile�� ���� ����
		auto avx = vx;

		volatile auto vavx = vx;
	}

	//template<class T>
	//void func_ex3(T arg)
	//{}

	//const &�� ������
	template<class T>
	void func_ex3(const T& arg)
	{}

	void ex3()
	{
		const int& crx = 123;
		
		//template���� const int&���� int�� �Ķ���ͷ� ��
		//-> ���� ��� �������
		func_ex3(crx);
	}

	void ex4()
	{
		const int c = 0;
		auto& rc = c;
		//rc = 123; -> error ���۷����� �����ö� const �������ٸ� auto�� const�� �߰���
	}

	void ex5()
	{
		int i = 42;
		auto&& ri_1 = i;	//l-value�� �޾Ƽ� ���۷����� �ٲ�
		auto&& ri_2 = 42;
	}

	void ex6()
	{
		int x = 42;
		const int* p1 = &x;
		auto p2 = p1;
		//*p2 = 43; -> error
	}

	//auto�� �ݵ�� �ʿ��� ���
	template<typename T,typename S>
	void func_ex7(T lhs, S rhs)
	{
		//���ϱ��� ���� � �������� �˱� ����� -> auto�� ����ؼ� �ذ�
		auto prod1 = lhs * rhs;

		//typedef typeof(lhs* rhs) product_type; //c++ 11����
		typedef decltype(lhs* rhs) product_type; //decltype ������ �� Ÿ�� 


		product_type prod2 = lhs * rhs; 

		decltype(lhs * rhs)prod3 = lhs * rhs;
	}

	template<typename T, typename S>
	//decltype(lhs * rhs)  func_ex8(T lhs, S rhs)  -> ��� �Ұ���
	auto func_ex8(T lhs, S rhs) ->decltype(lhs * rhs)
	{
		return lhs * rhs;
	}

	//��ȯ�� �ڷ��� Ȯ���غ���
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

		//decltype�� auto�� �ٸ��� const�� ���۷����� ������
		typedef decltype(x)		 x_type;
		typedef decltype(cx)	 cx_type;
		typedef decltype(crx)	 crx_type;
		typedef decltype(p->m_x) m_x_type; //int m_x�� const�� ������ �ȵǼ� �׳� int�� ������

		//��ȣ�� �ϳ� �� �־��ָ� ���۷����� ����
		typedef decltype((x))		r_x_type;
		typedef decltype((cx))		r_cx_type;
		typedef decltype((crx))		r_crx_type;
		typedef decltype((p->m_x))	r_m_x_type; //���۷����� ������ ���ÿ� const�� ����
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
		typedef decltype(foo()) foo_type; //const ����

		auto b = foobar();
		typedef decltype(foobar()) foobar_type;//const int& ����

		auto itr = vec.begin();
		typedef decltype(vec.begin()) itr_type;

		auto first_element = vec[0];
		decltype(vec[1]) second_element = vec[1];// vec[1]�� int&�� �����ؼ� ������
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

		typedef decltype(x < d2 ? x : d2) cond_type_mixed; //int�� double�� promotion
		auto d = x < d2 ? x : d2;

		//auto d= std::min(x,dbl); -> error �� �Ķ������ �ڷ����� �ٸ��� error�� ��
	}

	//T�� S�� �ڷ����� ������ ���Ͻ� ���۷����� �߰��� -> ������ �ɼ� ����
	template<typename T,typename S>
	auto fpmin_wrong(T x, S y) -> decltype(x < y ? x : y)
	{
		return x < y ? x : y;
	}

	//���۷����� ���ŵ� Ÿ���� ����Ѵ�
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
		typedef decltype(fpmin_wrong(d, d)) fpmin_type1;//���۷��� �߰�
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
		//���ٴ� �Ķ���Ϳ� auto��� ����
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
