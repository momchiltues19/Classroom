#ifndef POINT_HPP_
#define POINT_HPP_

#include <iostream>

class Point
{
	double x_, y_;
public: 
	Point (double x=0.0, double y=0.0)
	: x_(x), y_(y) {}
	
	double get_x() const
	{
		return x_;
	}

	double get_y() const
	{
		return y_;
	}
};

std::ostream& operator<<(std::ostream& out, const Point& p);

#endif
