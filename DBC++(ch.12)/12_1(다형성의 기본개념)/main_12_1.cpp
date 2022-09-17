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

	virtual void speak() const
	{
		cout << m_name << " ???" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{}

	void speak() const
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

	void speak() const
	{
		cout << m_name << " Woof" << endl;
	}

};


int main()
{
	Animal animal("temp animal");
	Cat cat("first cat");
	Dog dog("first dog");

	animal.speak();
	cat.speak();
	dog.speak();

	//캐스팅 시키면 부모클래스인줄 안다 -> virtual
	Animal* ptr_animal1 = &cat;
	Animal* ptr_animal2 = &dog;

	ptr_animal1->speak();
	ptr_animal2->speak();

	Cat cats[] = { Cat("cat1"),Cat("cat2") };
	Dog dogs[] = { Dog("dog1"),Dog("dog2"),Dog("dog3") };
	Animal* all_animal[] = { &cats[0],&cats[1],&dogs[0],&dogs[2],&dogs[1] };

	for (int i = 0; i < 5; ++i)
		all_animal[i]->speak();

	return 0;
}