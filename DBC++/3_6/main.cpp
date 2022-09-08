#include <iostream>
#include <bitset>//2진수 만들어줄 헤더 파일

int main()
{
	using namespace std;

	// << left shift
	// >> right shift

	unsigned int a = 3;
	
	cout << std::bitset<4>(a) << endl;

	cout << endl;
	cout << std::bitset<8>(a << 1) << ' ' << (a << 1) << endl; // 3 * 2^1
	cout << std::bitset<8>(a << 2) << ' ' << (a << 2) << endl; // 3 * 2^2
	cout << std::bitset<8>(a << 3) << ' ' << (a << 3) << endl; // 3 * 2^3
	cout << std::bitset<8>(a << 4) << ' ' << (a << 4) << endl;

	unsigned int a2 = 1024;

	cout << std::bitset<16>(a2) << endl;

	cout << endl;
	cout << std::bitset<16>(a2 >> 1) << ' ' << (a2 >> 1) << endl; // 3 * 2^1
	cout << std::bitset<16>(a2 >> 2) << ' ' << (a2 >> 2) << endl; // 3 * 2^2
	cout << std::bitset<16>(a2 >> 3) << ' ' << (a2 >> 3) << endl; // 3 * 2^3
	cout << std::bitset<16>(a2 >> 4) << ' ' << (a2 >> 4) << endl;



	cout << endl;

	unsigned int b = a << 1;

	unsigned int c = a << 2;

	cout << std::bitset<4>(b) << endl;
	cout << std::bitset<4>(c) << endl;


	// ~ , & , | , ^ 

	cout << endl;
	cout << std::bitset<32>(a2) << ' ' << a2 << endl;
	cout << std::bitset<32>(~a2) << ' ' << ~a2 << endl;
	

	cout << endl << '&' << endl;
	unsigned int d = 0b1100;
	unsigned int f = 0b0110;
	cout << std::bitset<4>(d) << endl << std::bitset<4>(f) << endl;
	cout << std::bitset<4>(d & f) << ' ' << (d & f) << endl;
	
	cout << endl << '|' << endl;
	cout << std::bitset<4>(d) << endl << std::bitset<4>(f) << endl;
	cout << std::bitset<4>(d | f) << ' ' << (d | f) << endl;
	
	cout << endl << '^' << endl;
	cout << std::bitset<4>(d) << endl << std::bitset<4>(f) << endl;
	cout << std::bitset<4>(d ^ f) << ' ' << (d ^ f) << endl;

	// a &= b 형식 사용가능

	int temp = 0b0110 >> 2;
	cout << endl << temp << endl;
	return 0;
}