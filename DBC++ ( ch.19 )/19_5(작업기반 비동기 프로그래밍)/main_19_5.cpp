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
		//thread�� ������ ���� ��ٸ�
		t.join();
		cout << result << endl;
	}

	//task-based parallelism
	{
		//async �񵿱����̴��� ����
		//�Ϲ������� async�� thread���� �� ��ȣ

		//������ �ٷ� ���´ٴ� ������ ���� -> �ð��� ���� �ɸ��� ������ ������ �����Ҽ��� ����
		//std::future<int> fut = ... -> �̷��� �������·� ���� �޾� ���ڴ�.
		//fut �� �ڿ� task�� ������ ��
		auto fut = std::async([] {return 1 + 2; });
		//get()�� Ư¡ �տ��� ������ �ɶ����� ��ٸ�
		cout << fut.get() << endl;
	}

	//future and promise
	{
		//thread���� future�� ����ϱ� ���� promise����ؾ���
		std::promise<int> prom;
		auto fut = prom.get_future();

		
		auto t = std::thread([](std::promise<int>&& prom)
		{
			prom.set_value(1 + 2);
		}, std::move(prom));

		cout << fut.get() << endl;
		t.join();
	}

	//thread�� async ������
	//�Ҹ��� ������ ���� �˾Ƽ� �������(async)
	//thread�� join�� �ؾ���
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


	//async�� thread �������̰� ����
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

		//join�� ������ ���װ� ����
		f1.join();
		f2.join();
	}
	cout << endl;
	//future�� �����ʴ� async
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