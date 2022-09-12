#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int main()
{
	//병렬처리 문제를 해결해주지만 속도는 느려짐
	//atomic<int> shared_memory(0);
	int shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(1));

			//mtx.lock();
			//std::lock_guard lock(mtx);
			//std::scoped_lock lock(mtx); -> 17이상부터 지원 가장 권장하는 방식

			shared_memory++;
			//mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);
	thread t3 = thread(count_func);

	t1.join();
	t2.join();
	t3.join();

	cout << "After: " << endl;
	cout << shared_memory << endl;

	return 0;
}