#ifndef LITERAL_HH
#define LITERAL_HH

#include "operation.hh"

class Literal : public Operation
{
	double val_;
public:
	Literal(Calculator& calc, double val);
	void eval();
};

#endif
