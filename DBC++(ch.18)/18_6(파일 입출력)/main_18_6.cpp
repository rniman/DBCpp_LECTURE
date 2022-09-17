#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>//exit()
#include <sstream>

using namespace std;

int main()
{
	//write
	if (false)
	{
		//ofstream ofs("my_file.dat");
		ofstream ofs("my_file.dat",ios::app);//append 모드는 기존파일에 추가로 덧붙여서 실행함
		//ofs.open("my_file.dat");

		if (!ofs)
		{
			cerr << "fail open file" << endl;
			exit(1);
		}

		ofs << "Line1" << endl;
		ofs << "Line2" << endl;

		ofs.close(); // not necessary
	}

	//read
	if (false)
	{
		ifstream ifs("my_file.dat");

		if (!ifs)
		{
			cerr << "fail open file" << endl;
			exit(1);
		}

		while (ifs)
		{
			string str;
			getline(ifs, str);

			cout << str << endl;
		}
	}

	//write binary
	if (true)
	{
		ofstream ofs("my_file.dat");
		//ofs.open("my_file.dat");

		if (!ofs)
		{
			cerr << "fail open file" << endl;
			exit(1);
		}

		//가장먼저 데이터의 갯수를 저장함
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));

		ofs.close(); // not necessary
	}

	//read binary
	if (true)
	{
		ifstream ifs("my_file.dat");

		if (!ifs)
		{
			cerr << "fail open file" << endl;
			exit(1);
		}

		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));
			cout << num << endl;
		}
			

		ifs.close(); // not necessary

	}

	const string fileName = "temp.txt";
	{
		ofstream ofs(fileName);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	{
		ifstream ifs(fileName);
		ifs.seekg(5);
		cout << (char)ifs.get() << endl;

		ifs.seekg(1, ios::cur);
		cout << (char)ifs.get() << endl;

		string str;
		getline(ifs, str);
		cout << str << endl;

		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl;
	}

	{
		fstream iofs(fileName);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl;

		iofs.seekg(5);
		iofs.put('|');
	}

	return 0;
}