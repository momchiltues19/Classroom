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
		return *this; 
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
	
	Point& add(const Point& other) 
	{
		x_ += other.x_;
		y_ += other.y_;
		return *this;
	}
	Point& sub(const Point& other) 
	{
		x_ -= other.x_;
		y_ -= other.y_;
		return *this;
	}
	Point& mul(double a)
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

	Point& operator-=(const Point& other)
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

istream& operator>>(istream& in, Point& p)
{  
	char ch;
	double x=0, y=0;
	in >> ch; //(	
	if (ch!='(')
	{
		in.clear(ios_base::badbit);
		return in;
	}
	in >> x; 
	in >> ch; //,
	if (ch!=',')
	{
		in.clear(ios_base::badbit);
		return in;
	}	
	in >> y; 
	in >> ch; //)
	if (ch!=')')
	{
		in.clear(ios_base::badbit);
		return in;
	}
	
	if (in.good())
	{
		p.set_x(x).set_y(y);
	}	
	return in;
}

int main()
{
	Point p0;
	p0.set_x(0).set_y(0);
	Point p1(0,0), p2(0,0), p3(0,0);
	
	cout << "Before actions: " << endl;
	cout << "p0 is " << p0;
	cout << "p1 is " << p1;
	cout << "p2 is " << p2;
	cout << "p3 is " << p3;

	cin >> p1 >> p2;
	if(!cin.good())
	{
		cout << "fail" << endl;
	}
	cout << "After actions: " << endl;
	cout << "p0 is " << p0;
	cout << "p1 is " << p1;
	cout << "p2 is " << p2;
	cout << "p3 is " << p3;

	return 0;
}
