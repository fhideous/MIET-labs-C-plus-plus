#ifndef CPP_LAB_AVERGE_H
#define CPP_LAB_AVERGE_H

#include "Point.h"

template<typename T>

T averge(const std::vector<T> &vec)
{
	T res = 0;
	int i = 0;

	while (i < vec.size())
	{
		res += vec[i];
		i++;
	}
	res /= vec.size();
	return res;
}

template<typename T>
Point<T> averge(const std::vector<Point<T>> &pnt)
{
	Point<T> res;
	int i = 0;

	while (i < pnt.size())
	{
		res.x += pnt[i].x;
		res.y += pnt[i].y;
		i++;
	}
	res.x /= pnt.size();
	res.y /= pnt.size();
	return res;
}

#endif