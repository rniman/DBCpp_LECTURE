#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

//���� �Լ��� ����
unsigned int PRNG()
{
	using namespace std;

	//�õ� �ѹ�
	static unsigned int seed = 5523; 

	seed = 8253729 * seed + 2396403;

	return seed % 32768;
}

int getRandomNum(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);

	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}


int main()
{
	using namespace std;

	//�õ� ���� -> ������� �� �õ� ���� ��Ű��
	std::srand(5323);
	
	std::srand(static_cast<unsigned int>(std::time(0)));

	//ū���������� ������ ������ ������ �߻��� �� ����
	rand() % 5 + 3; 

	//random ���̺귯��
	std::random_device rd;
	std::mt19937_64 mersenne(rd());
	std::uniform_int_distribution<> dice(1, 6); //������ Ȯ��





	for (int i = 1; i <= 100; ++i) 
	{
		//cout << PRNG() << '\t';
		//cout << getRandomNum(5, 8) << '\t';
		cout << dice(mersenne) << '\t';
		if (i % 5 == 0)cout << endl;
	}


	return 0;
}