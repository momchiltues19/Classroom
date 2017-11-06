#include <iostream>
using namespace std;

class Point {
	double x_, y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y) {}

	double get_x() const
	{	
		return x_;
	}	
	double get_y() const	
	{
		return y_;
	}	
	Point& set_x(double x)
	{
		x_ = x;
		return *this; //kvo y stava na taz' vrata
	}
	Point& set_y(double y)
	{
		y_ = y;
		return *this;
	}
	
	void print()
	{
		cout << "(" << this->get_x() << "," << this->get_y() << ")" << endl;
	}
	
	Point& add(const Point& other) // p.add(o) -> p += o 
	{
		x_ += other.x_;
		y_ += other.y_;
		return *this;
	}
	Point& sub(const Point& other) // p.sub(o) -> p -= o
	{
		x_ -= other.x_;
		y_ -= other.y_;
		return *this;
	}
	Point& mul(double a) // p.mul(a) -> p *= a
	{
		x_ *= a;
		y_ *= a;
		return *this;
	}
	
	Point operator+(const Point other) const
	{
		Point result(x_, y_);
		result.add(other);
		return result;
	}
	
	Point operator-(void) const
	{
		Point result(-x_, -y_);
		return result;
	}

	Point& operator-=(const Point& other) //tozi red e with the help of Stefka
	{
		x_ -= other.x_;
		y_ -= other.y_;
		return *this;
	}
};

Point operator-(const Point& p1, const Point& p2)
{
	Point result(p1.get_x(), p1.get_y());
	result -= p2;
	return result;
}
ostream& operator<<(ostream& out, const Point& p)
{
	out << "(" << p.get_x() << "," << p.get_y() << ")" << endl;  
	return out;
}

int main()
{
	Point p0;
	p0.set_x(1).set_y(1);
	Point p1(2,2), p2(3,3), p3(4,4);
	
	cout << "Before actions: " << endl;
	cout << "p0 is " << p0;
	cout << "p1 is " << p1;
	cout << "p2 is " << p2;
	cout << "p3 is " << p3;
	//p0.add(p2).sub(p3); //we want p0 = p + p2 - p3
	//p3.add(p4); //we want p3 += p4
	p0 = -p2;
	p3 -= p2;
	//p0 = p1 + -p3;
	cout << "After actions: " << endl;
	cout << "p0 is " << p0;
	cout << "p1 is " << p1;
	cout << "p2 is " << p2;
	cout << "p3 is " << p3;

	return 0;
}
