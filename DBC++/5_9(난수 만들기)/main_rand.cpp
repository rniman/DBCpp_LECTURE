#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

//랜덤 함수의 원리
unsigned int PRNG()
{
	using namespace std;

	//시드 넘버
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

	//시드 고정 -> 디버깅할 때 시드 고정 시키기
	std::srand(5323);
	
	std::srand(static_cast<unsigned int>(std::time(0)));

	//큰범위에서는 난수가 몰리는 문제가 발생할 수 있음
	rand() % 5 + 3; 

	//random 라이브러리
	std::random_device rd;
	std::mt19937_64 mersenne(rd());
	std::uniform_int_distribution<> dice(1, 6); //동일한 확률





	for (int i = 1; i <= 100; ++i) 
	{
		//cout << PRNG() << '\t';
		//cout << getRandomNum(5, 8) << '\t';
		cout << dice(mersenne) << '\t';
		if (i % 5 == 0)cout << endl;
	}


	return 0;
}