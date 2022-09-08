#include <iostream>
#include <bitset>

int main()
{
	using namespace std;

	//������, ����, ���ƿ�, ����, ����
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

	//��縦 ����
	my_article_flags |= option_viewed;
	cout << "��縦 �ô�!\t" << std::bitset<8>(my_article_flags) << endl;

	//��� ���ƿ並 ����
	my_article_flags |= option_liked;
	cout << "��� ���ƿ�!\t" << std::bitset<8>(my_article_flags) << endl;

	//��� ���ƿ並 ����
	my_article_flags &= ~option_liked;
	cout << "��� ���ƿ� ���!\t" << std::bitset<8>(my_article_flags) << endl;

	//�� ��� ����
	if (my_article_flags & option_viewed) {
		my_article_flags |= option_deleted;
		cout << "��� ����!" << std::bitset<8>(my_article_flags) << endl;
	}
	
	return 0;
}