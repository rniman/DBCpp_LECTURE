//�ϳ��� ���μ����� �������� �����带 Ȱ���Ѵ�
//��Ƽ ������: �������� �����尡 �޸𸮸� ������
//��Ƽ�ھ�CPU���� �ڵ����� ��Ƽ�������� �ϵ��� �ϴ� ���� �ƴ�
//��Ƽ �������� �ϵ��� ���α׷����� �ؾ���

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std;

mutex mtx; // mutual exclusion

int main()
{
	//���μ����� ������ ������
	//cout << std::thread::hardware_concurrency() << endl;

	//main function�� ����ǰ��ִ� �������� ID�� �������
	//cout << std::this_thread::get_id() << endl;

	//const int num_pro = std::thread::hardware_concurrency();

	//������ �� -> ���� ���� ������� �۵��� �ϸ鼭 main()�� �ǻ������ �ؾ��ϴµ� main()�� ���� -> join()
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

	//t1�� ���������� ��ٸ�
	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();

	//������ �������� ������� �ڵ�
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

			//��ºκ��� �ϳ��� �����常 �ǵ帲 -> ������ �ϳ��� ���
			//Ǯ������ ������ �ѹ� �۵��� ����� ����
			mtx.lock();
			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();
		}
	};

	//jackjack�� ����Ʈ �ϴµ��� Dash�� �������� -> ��Ƽ �������� ���
	//work_func("jackJack");
	//work_func("Dash");

	//�ΰ��� �Լ��� ���ÿ� �۵��Ͽ��� ����� ���׹����ϰ� ����
	//<mutex>�� �������
	std::thread t1 = std::thread(work_func, "JackJack");
	std::thread t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}