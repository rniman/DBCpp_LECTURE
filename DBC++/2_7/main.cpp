#include <iostream>
#include <limits>

int main()
{
	using namespace std;


	char c1(65);
	char c2('A');

	cout << c1 << endl;
	cout << c2 << endl;

	//cpp스타일 캐스팅 
	cout << endl;
	cout << int(c1) << endl;
	cout << int(c2) << endl;
	
	//c스타일 캐스팅
	cout << endl;
	cout << (int)c1 << endl;
	cout << (int)c2 << endl;

	cout << endl;
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	cout << endl;
	cout << (int)numeric_limits<char>::max() << endl;
	cout << (int)numeric_limits<char>::lowest() << endl;
	cout << (int)numeric_limits<unsigned char>::max() << endl;
	cout << (int)numeric_limits<unsigned char>::lowest() << endl;

	char c;
	
	cin >> c;  cout << c << " " << static_cast<int>(c) << endl;
	cin >> c; cout << c << " " << static_cast<int>(c) << endl; 
	cin >> c; cout << c << " " << static_cast<int>(c) << endl;
	cin >> c; cout << c << " " << static_cast<int>(c) << endl;
	cin >> c; cout << c << " " << static_cast<int>(c) << "\n";
	cin >> c; cout << c << " " << static_cast<int>(c) << "\n"; 
	cin >> c; cout << c << " " << static_cast<int>(c) << "\n";
	cin >> c; cout << c << " " << static_cast<int>(c) << "\n";


	return 0;
}