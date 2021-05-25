#ifndef CPP_LAB_POINT_H
#define CPP_LAB_POINT_H

template <class T>
class Point
{
public:
	Point() = default;
	~Point(){};
	T x;
	T y;
	Point(int n):
	x(n), y(n) {};

};

template <class T>
Point<T> operator + (const Point<T> &p1, const Point<T> &p2)
{
	Point<T> res;
	res.x = p1.x + p2.x;
	res.y = p2.y + p1.y;
	return res;

}

template <class T>
Point<T> operator / (const Point<T> &p1, const int n)
{
	Point<T> res;
	res.x = p1.x / n;
	res.y = p1.y / n;
	return res;
}


#endif