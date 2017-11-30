#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "point.hpp"
#include "shape.hpp"

class Circle: public Shape
{
	Point centre_;
	double radius_;
public:
	Circle(const Point& p, double radius);
	
	void draw() const;
};

#endif
