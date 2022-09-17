#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>
#include <execution>

using namespace std;

mutex mtx;

void dotProductNative(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];;
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long& sum)
{	
	//lock �ɸ��κ��� �������� ����

	//cout << "Thread Start" << endl;
	for (unsigned i = i_start; i < i_end; i++)
	{
		//mtx.lock();

		//c++ 17�̻�
		//for�� �ۿ��� �����带 �ϸ� ������ �ƴ� ���������� ������ �Ǿ����
		//�ȿ� ������ ���� -> ���� ����ϰ� ����Ǿ� ��������
		std::scoped_lock lock(mtx);
		sum += v0[i] * v1[i];
	
		//mtx.unlock();
	}

	//cout << "Thread end" << endl;
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, atomic<unsigned long long>& sum)
{
	//����� ������ ����ϰ� �Ͼ�� ����
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];;
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0;
	//����� ������ ����ϰ� �Ͼ�� ����
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];;

	return sum;
}

int main()
{
	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;

	//initialize vectors
	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937_64 engine(seed());

	uniform_int_distribution<> uni(1, 10);

	for (long long i = 0; i < n_data; ++i)
	{
		v0.push_back(uni(engine));
		v1.push_back(uni(engine));
	}

	cout << "std::inner_product" << endl;
	{
		//�ð���
		const auto sta = chrono::steady_clock::now();

		//0ull-> unsigned long long ->auto�� ����� ����
		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;

	}

	//race condition�� �ذ��ؾ���
	cout << "Native" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; //assumes remainder(������ 0) = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductNative, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;
	
		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	//lock guard �̿� -> Ȯ���� ������
	cout << "Lock Guard" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; //assumes remainder(������ 0) = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	//����͵� ����
	cout << "Atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; //assumes remainder(������ 0) = 0
		for (unsigned t = 0; t < n_threads; ++t)
			threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

		for (unsigned t = 0; t < n_threads; ++t)
			threads[t].join();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	//�����̾ƴ� ���ÿ��� ���� ���� ��������
	//thread�� ������ ����
	cout << "Future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<std::future<int>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads; //assumes remainder(������ 0) = 0
		for (unsigned t = 0; t < n_threads; ++t)
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t * n_per_thread, (t + 1) * n_per_thread);

		for (unsigned t = 0; t < n_threads; ++t)
			sum += futures[t].get();

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	cout << "std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;

	}

	//divide and conquer for std::thread,atomic
	//promise

	return 0;
}