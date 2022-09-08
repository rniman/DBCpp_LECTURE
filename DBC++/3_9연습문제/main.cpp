#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	//기사봤음, 수정, 좋아요, 공유, 삭제
	unsigned char option_viewed = 0x01;
	unsigned char option_edited = 0x02;
	unsigned char option_liked = 0x04;
	unsigned char option_share = 0x08;
	unsigned char option_deleted = 0x80;

	cout << std::bitset<8>(option_viewed) << endl;
	cout << std::bitset<8>(option_edited) << endl;
	cout << std::bitset<8>(option_liked) << endl;
	cout << std::bitset<8>(option_share) << endl;
	cout << std::bitset<8>(option_deleted) << endl;

	
	unsigned char my_article_flags = 0;
	cout << "Now: " << std::bitset<8>(my_article_flags) << endl;

	//기사를 봤음
	my_article_flags |= option_viewed;
	cout << "기사를 봤다!\t" << std::bitset<8>(my_article_flags) << endl;

	//기사 좋아요를 누름
	my_article_flags |= option_liked;
	cout << "기사 좋아요!\t" << std::bitset<8>(my_article_flags) << endl;

	//기사 좋아요를 누름
	my_article_flags &= ~option_liked;
	cout << "기사 좋아요 취소!\t" << std::bitset<8>(my_article_flags) << endl;

	//본 기사 삭제
	if (my_article_flags & option_viewed) {
		my_article_flags |= option_deleted;
		cout << "기사 삭제!" << std::bitset<8>(my_article_flags) << endl;
	}
	
	return 0;
}