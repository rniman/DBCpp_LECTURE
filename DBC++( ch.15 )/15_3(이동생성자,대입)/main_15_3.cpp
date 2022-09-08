#include "Timer.h"
#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generatResource()
{
	AutoPtr<Resource> res(new Resource(100000000));

	return res;
}

int main()
{
	using namespace std;
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL);

	Timer timer;

	{
		AutoPtr<Resource> main_res;
		main_res = generatResource();
	}

	cout.rdbuf(orig_buf);
	timer.elapsed();

	return 0;
}