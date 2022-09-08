#include <iostream>


namespace smg
{
	int pow(const int left,const int right)
	{
		int initial = 1;
		
		if (right == 0) {
			return 1;
		}
		else if (right < 0) {
			for (int i = 0; i < right; ++i) {
				initial /= left;
			}
		}
		else {
			for (int i = 0; i < right ; ++i) {
				initial *= left;
			}
		}

		return initial;
	}


}

int main()
{
	std::cout << smg::pow(3, 3) << std::endl;

	return 0;
}