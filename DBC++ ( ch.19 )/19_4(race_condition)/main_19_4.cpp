#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int main()
{
	//����ó�� ������ �ذ��������� �ӵ��� ������
	//atomic<int> shared_memory(0);
	int shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(1));

			//mtx.lock();
			//std::lock_guard lock(mtx);
			//std::scoped_lock lock(mtx); -> 17�̻���� ���� ���� �����ϴ� ���

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