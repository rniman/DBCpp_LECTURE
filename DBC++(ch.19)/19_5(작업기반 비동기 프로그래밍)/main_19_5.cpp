#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	//multi-threading
	{
		int result;
		std::thread t([&] {result = 1 + 2; });
		//thread가 끝날때 까지 기다림
		t.join();
		cout << result << endl;
	}

	//task-based parallelism
	{
		//async 비동기적이다의 약자
		//일반적으로 async를 thread보다 더 선호

		//리턴이 바로 들어온다는 보장이 없다 -> 시간이 오래 걸리는 복잡한 연산을 수행할수도 있음
		//std::future<int> fut = ... -> 미래에 정수형태로 값을 받아 오겠다.
		//fut 는 뒤에 task와 결합이 됨
		auto fut = std::async([] {return 1 + 2; });
		//get()의 특징 앞에서 리턴이 될때까지 기다림
		cout << fut.get() << endl;
	}

	//future and promise
	{
		//thread에서 future을 사용하기 위해 promise사용해야함
		std::promise<int> prom;
		auto fut = prom.get_future();

		
		auto t = std::thread([](std::promise<int>&& prom)
		{
			prom.set_value(1 + 2);
		}, std::move(prom));

		cout << fut.get() << endl;
		t.join();
	}

	//thread와 async 차이점
	//소멸자 끝나는 것을 알아서 대기해줌(async)
	//thread는 join을 해야함
	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		cout << "Main function" << endl;
	}


	//async와 thread 문법차이가 있음
	{
		auto f1 = std::thread([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		auto f2 = std::thread([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		cout << "Main function" << endl;

		//join이 없으면 버그가 생김
		f1.join();
		f2.join();
	}
	cout << endl;
	//future을 받지않는 async
	{
		std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
			});

		std::async([] {
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		cout << "Main function" << endl;
	}

	return 0;
}