#include "circle.hpp"

using namespace std;
Circle::Circle(const Point& p, double radius)
: centre_(p), radius_(radius) {}

void Circle::draw() const 
{
		cout << "C(" << centre_ << ", " << radius_ << ")" << endl;
}
