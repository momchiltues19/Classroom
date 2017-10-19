#include <iostream>
using namespace std;

class Point
{
	double x_, y_;
	const double cx_, cy_;
public:	
	static const double DEFAULT_CX_ = 0, DEFAULT_CY_ = 0;
	Point(double x, double y, double cx, double cy) 
	: x_(x), y_(y), cx_(cx), cy_(cy) {}

	Point(double x, double y) 
	: x_(x), y_(y), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}

	static Point get_default_beginning() //static vs const - const needs an object -> does not compile
	{		
		return Point(DEFAULT_CX_, DEFAULT_CY_);
	}
	
	double get_x() const //we make it const because IT IS a const
	{
		return x_;
	}
	double get_y() const
	{
		return y_;
	}
	double get_cx() const
	{
		return cx_;
	}
	double get_cy() const
	{
		return cy_;
	}
	Point& set_x(double x)
	{
		x_ = x;
		return *this;
	}
	Point& set_y(double y)
	{
		//this; //Point*		
		y_ = y;
		return *this;
	}
	void print() const //a non-const funct cannot use a const object
	{
		this; //const Point* const; also, this is mostly used for same name vars 		
		cout << "(" << x_ << "," << y_ << ")" << " in "
			 << "(" << cx_ << "," << cy_ << ")" << endl; 
	}
	Point transform_in_default()
	{
		return transform_in(DEFAULT_CX_, DEFAULT_CY_);
	}
	Point transform_in(double new_cx, double new_cy)
	{
		return Point(x_ + cx_ - new_cx, y_ + cy_ - new_cy, new_cx, new_cy);
	}
};
	
int main()
{	
	/*	
	char* pchar; //points to char
	const char* cpchar; //points to const char
	char* const pcharc; //const pointer to char <- this falls here
	const char *const cpcharc; //const pointer to const char	
	*/
	const Point orig(0,0);			
	
	Point p1(1,1);
	Point p2(2,2,1,1);
	
	Point& rp = p1; 
	const Point& crp = p2;
		
	//crp.set_x(1); //does not compile (cannot change const)
	crp.get_x(); //works, because we don't change anything	
	rp.set_x(1);
	rp.get_x(); //both work	
	
	p2.set_y(2.1).set_x(3.2);
	cout << "p2 is " << endl; p2.print();
	p1.set_x(3.0).set_y(3.0);	
	cout << "p1 is " << endl; p1.print();	
	return 0;
}
