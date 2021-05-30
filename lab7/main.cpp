#include <iostream>
#include <vector>
#include "averge.h"
#include "Point.h"

int main()
{
	std::vector<int> arr_int = {1,2,3,4,5};
	std::vector<float> arr_float = {2,2.0,3.0,4.0,5.0};

	std::vector<Point<int>> points_int;
	int i = 6;
	while (--i)
	{
		Point<int> point_int;
		point_int.x = i;
		point_int.y = i + 6;
		points_int.push_back(point_int);
	}
	Point<int> av_points = averge(points_int);
	int in = averge(arr_int);
	float fl = averge(arr_float);
	std::cout <<"int:\t" << in << "\n" << "float:\t"<< fl << "\n" <<
			"points:\tx = " << av_points.x << "\ty = "<< av_points.y;
	return 0;
}