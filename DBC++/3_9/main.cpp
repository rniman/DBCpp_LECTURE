#include <iostream>
#include <bitset>


int main()
{
	using namespace std;

	//비트 플래그 option0~ option7 까지
	const unsigned char opt0 = 1 << 0;
	const unsigned char opt1 = 1 << 1;
	const unsigned char opt2 = 1 << 2;
	const unsigned char opt3 = 1 << 3;
	const unsigned char opt4 = 1 << 4;
	const unsigned char opt5 = 1 << 5;
	const unsigned char opt6 = 1 << 6;

	cout << std::bitset<8>(opt0) << endl;
	cout << std::bitset<8>(opt1) << endl;
	cout << std::bitset<8>(opt2) << endl;
	cout << std::bitset<8>(opt3) << endl;
	cout << std::bitset<8>(opt4) << endl;
	cout << std::bitset<8>(opt5) << endl;
	cout << std::bitset<8>(opt6) << endl;


	//현재 상태?-> 아이템 없음
	unsigned char items_flag = 0;
	cout << std::bitset<8>(items_flag) << endl;

	cout << endl;
	//item0 ON
	items_flag |= opt0;
	cout <<"item0 ON\t" << std::bitset<8>(items_flag) << endl;

	//item3 ON
	items_flag |= opt3;
	cout << "item3 ON\t" << std::bitset<8>(items_flag) << endl;

	//item3 OFF
	items_flag &= ~opt3;
	cout << "item3 OFF\t" << std::bitset<8>(items_flag) << endl;

	//item4 ON
	items_flag |= opt4;
	cout << "item4 ON\t" << std::bitset<8>(items_flag) << endl;

	cout << endl;
	//item0 is TRUE? 
	if (items_flag & opt0) {
		cout <<"item0 is ON\t" << std::bitset<8>(items_flag) << endl;
	}
	else {
		cout << "item0 is Off\t" << std::bitset<8>(items_flag) << endl;
	}

	//item1 is TRUE? 
	if (items_flag & opt1) {
		cout << "item1 is ON\t" << std::bitset<8>(items_flag) << endl;
	}
	else {
		cout << "item1 is Off\t" << std::bitset<8>(items_flag) << endl;
	}

	//have item 2, 3
	items_flag |= (opt2 | opt3);
	cout << "Now item\t" << std::bitset<8>(items_flag) << endl;

	//lost item 0, 3
	items_flag &= ~(opt0 | opt3);
	cout << "Now item\t" << std::bitset<8>(items_flag) << endl;

	
	cout << endl;
	//change item 2 -> 1
	if ((items_flag & opt2) && !(items_flag & opt1)) 
	{
		//items_flag ^= (opt2 | opt1);
		items_flag ^= opt2;
		items_flag ^= opt1;

		cout << "Now item\t" << std::bitset<8>(items_flag) << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;

	//비트마스크
	//rgb color table -> 16진수로 표현 RRGGBB -> #FF00FF ->(255,0,255)

	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << std::bitset<32>(red_mask) << endl;
	cout << std::bitset<32>(green_mask) << endl;
	cout << std::bitset<32>(blue_mask) << endl;


	unsigned int pixel_color = 0xDAA520;

	cout << endl;
	cout << std::bitset<32>(pixel_color) << endl;
	
	//red green blue가 알고싶다
	unsigned char red = (pixel_color&  red_mask) >> 16;
	unsigned char green = (pixel_color & green_mask) >> 8;
	unsigned char blue = pixel_color & blue_mask;

	cout << "red\t" << std::bitset<8>(red) << " " << int(red) << endl;
	cout << "green\t" << std::bitset<8>(green) << " " << int(green) << endl;
	cout << "blue\t" << std::bitset<8>(blue) << " " << int(blue) << endl;

	return 0;
}