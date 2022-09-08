#include <string>
#include <cstddef>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	{
		std::string string_class;
		std::wstring wstring_class;

		//wide-character , unicode
		//국제어를 사용할때 사용
		wchar_t wc;
	}

	{
		const std::wstring tests[] =
		{
			L"Hello",
			L"안녕하세요",
			L"Ñá", //Spanish
			L"forêt intérêt", //French
			L"Gesäß", //German
			L"取消波蘇日奇諾", //Chinese
			L"日本人のビット", //Japanese
			L"немного русский", //Russian
			L"ένα κομμάτι της ελληνικής", // Greek
			L"ਯੂਨਾਨੀ ਦੀ ਇੱਕ ਬਿੱਟ", // Punjabi (wtf?). xD
			L"کمی از ایران ", // Persian (I know it, from 300 movie)
			L"కానీ ఈ ఏమి నరకం ఉంది?", //Telugu (telu-what?)
			L"Но какво, по дяволите, е това?", //Bulgarian
		};

		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale());

		for (size_t i = 0; i < 13; ++i)
			std::wcout << tests[i] << endl;

	}

	return 0;
}