//하나의 프로세스가 여러개의 쓰레드를 활용한다
//멀티 쓰레드: 여러개의 쓰레드가 메모리를 공유함
//멀티코어CPU에서 자동으로 멀티쓰레딩을 하도록 하는 것이 아님
//멀티 쓰레딩을 하도록 프로그래밍을 해야함

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion

int main()
{
	//프로세스의 개수를 가져옴
	//cout << std::thread::hardware_concurrency() << endl;

	//main function이 실행되고있는 쓰레드의 ID를 출력해줌
	//cout << std::this_thread::get_id() << endl;

	//const int num_pro = std::thread::hardware_concurrency();

	//오류가 남 -> 새로 생긴 쓰레드는 작동을 하면서 main()과 의사소통을 해야하는데 main()이 끝남 -> join()
	//std::thread t1 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true)
	//	{}
	//	}
	//);

	//std::thread t2 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true)
	//	{}
	//	}
	//);

	//std::thread t3 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true)
	//	{}
	//	}
	//);

	//std::thread t4 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true)
	//	{}
	//	}
	//);

	//t1이 끝날때까지 기다림
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();

	//쓰레드 극한으로 써버리는 코드
	//vector<std::thread> my_threads;
	//my_threads.resize(num_pro);

	//for (auto& e : my_threads)
	//{
	//	e = std::thread([]() {
	//		cout << std::this_thread::get_id() << endl;
	//		while (true)
	//		{}
	//		}
	//	);
	//}

	//for (auto& e : my_threads)
	//	e.join();


	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			//출력부분은 하나의 쓰레드만 건드림 -> 쓰레드 하나가 잠금
			//풀어주지 않으면 한번 작동후 기능이 막힘
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();
		}
	};

	//jackjack을 프린트 하는동안 Dash는 쉬고있음 -> 멀티 쓰레딩을 사용
	//work_func("jackJack");
	//work_func("Dash");

	//두개의 함수가 동시에 작동하여서 출력이 뒤죽박죽하게 나옴
	//<mutex>를 사용하자
	std::thread t1 = std::thread(work_func, "JackJack");
	std::thread t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}