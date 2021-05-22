#include <iostream>
#include <vector>
#include "averge.h"

int main()
{
	std::vector<int> arr_int = {1,2,3,4,5};
	std::vector<float> arr_float = {2,2.0,3.0,4.0,5.0};

	int i = averge(arr_int);
	float f = averge(arr_float);
	std::cout << i << "\n" << f;
	return 0;
}