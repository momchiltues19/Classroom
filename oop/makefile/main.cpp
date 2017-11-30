#include <iostream>
#include "point.hpp"
#include "circle.hpp"
using namespace std;

int main()
{
	Point p1, p2;
	Circle c1(p1, 2);
	cout << p1 << endl << p2 << endl;
	c1.draw();	
	return 0;
}
