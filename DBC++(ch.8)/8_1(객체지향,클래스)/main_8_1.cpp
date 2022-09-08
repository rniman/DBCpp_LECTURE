#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Object 객체
//데이터와 기능이 묶여있는것을 Object라고 한다.

//Object를 class로 표현
class Friend
{
//구조체는 access specifier가 안들어간다
public:	//access specifier (public, private , protected)
	string m_name = "empty";
	string m_address = "empty";
	int	   m_age = 0;
	double m_height = 0;
	double m_weight = 0;

	void print_data()
	{
		cout << m_name << " " << m_address << " " << m_age << " " <<
			m_height << " " << m_weight << " " << endl;
	}
};

//void print(const Friend& friend_data)
//{
//	cout << friend_data.name << " " << friend_data.address << " " << friend_data.age << " " <<
//		friend_data.height << " " << friend_data.weight << " " << endl;
//}


int main()
{

	Friend jj{ "Jack Jack","Busan",15,50,175 };		//instanciation
	vector<Friend> my_friends;

	my_friends.resize(2);
	my_friends[0].print_data();
	my_friends[1].print_data();

	cout << endl;
	for (auto& element : my_friends)
		element.print_data();

	jj.print_data();
	//print(jj);

	//vector<string> name_vec;
	//vector<string> address_vec;
	//vector<int>	   age_vec;
	//vector<double> height_vec;
	//vector<double> weight_vec;



	return 0;
}