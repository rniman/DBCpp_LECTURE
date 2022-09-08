#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	char buf[5];

	//setw -> 최대 글자수 만큼 받을수 있도록 방지해줌
	cin >> setw(5) >> buf;

	cout << buf << endl;


	//버퍼에 글자가 남아있다면 가져옴
	cin >> setw(5) >> buf;

	cout << buf << endl;


	//빈칸도 읽어드림 버퍼를 비우지는 않음
	cin.get(buf, 5);
	
	//빈칸도 읽어드림 입력한 줄을 다 받아서 버퍼가 비워짐
	//\0도 읽어드려서 gcount시 1이 더해짐
	cin.getline(buf, 5);


	//몇글자 읽어왔는지 알수있음
	cout << cin.gcount();

	string str_buf;

	getline(cin, str_buf);
	//0을 출력한다
	cout << cin.gcount() << endl;

	//숫자만큼 입력한 문자열의 앞부분을 무시함
	cin.ignore(/*숫자*/);

	//버퍼에서 글자를 읽어오지만 버퍼에 그대로 남겨둔다
	cout << (char)cin.peek() << endl;

	//버퍼를 읽은후 마지막에 읽은 글자를 버퍼에 다시넣음
	cin.unget();

	//버퍼에 'A'를 넣음
	cin.putback('A');

	return 0;
}