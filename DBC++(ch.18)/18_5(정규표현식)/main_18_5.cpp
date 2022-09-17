#include <iostream>
#include <regex>
using namespace std;

int main()
{
	//regex re("\\d");
	//regex re("\\d+");//여러숫자가능
	//regex re("[[:digit:]]{3}");
	//regex re("[A-Z]+");
	//regex re("[A-Z]{1,5}");
	regex re("([0-9]{1})([-]?)([0,9]{1,4})"); //-가 사이에 있어도 되고 없어도 된다

	string str;
	while (1)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}

	}

	return 0;
}