#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		:m_name(name)
	{}

	string getName() { return m_name; }

	//pure virtual function
	//��ü�� ����
	virtual void speak() const = 0;
};

class Cat : public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << " Meow" << endl;
	}

};

class  Dog :public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << " Woof" << endl;
	}

};

class  Cow :public Animal
{
public:
	Cow(string name)
		:Animal(name)
	{}

	virtual void speak() const
	{
		cout << m_name << " Moooo" << endl;
	}
};


int main()
{
	//pure virtual function�� ������
	//������ �Ұ���
	//Animal a("AA");

	//pure virtual function�� ������
	//�������̵��� ������
	Cow c("CC");
	c.speak();

	return 0;
}