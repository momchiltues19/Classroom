#ifndef COMPOSITE_HH
#define COMPOSITE_HH

#include <string>
#include <list>
#include "operation.hh"

class Composite: public Operation
{

public:
	Composite(Calculator& calculator; const std::string& name);
	
	void add_child(Operation* op);

	void eval();

};

#endif
