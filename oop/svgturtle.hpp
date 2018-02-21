#ifndef TURTLE_HPP_
#define TURTLE_HPP_

#include "turtle.hh"
#include "point.hh"

class SVGTurtle: public Turtle
{
		std::ostream& out_;

public:
	SVGTurtle(double width, double heigth, std::ostream& out)
	: Turtle(width, heigth), out_(out) {}
	~SVGTurtle()
	{
		out_ << "</svg>" << endl << "</body>" << endl << "</html>";
	}
	Turtle& setup()
	{
		out_ << "<html>" << endl << "<body>" << endl
			 << "<h1>SVG Turtle Graphics</h1>" << endl
			 << "<svg width=\"" << width 
			 << "\" heigth=" << heigth << "\">" << endl;
	}
	Turtl& moveto(const Point& p)
	{
		if(is_pendown())
			out_ << "<line x1=\"" << pos_.get_x() << "\" y1=\"" << pos_.get_y()
			     << "\" x2=\"" << p.get_x() << "\" y2=\"" << p.get_y() << "\" style=\"strike:rgb("
				 << get_color() << ");stroke-width:" << get_pensize() << endl;
	}
}

#endif
