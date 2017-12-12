#ifndef UNARY_HPP
#define UNARY_HPP

#include "calculator.hpp"
#include "operation.hpp"

class UnaryOperation : public Operation
{

public:
	UnaryOperation(Calculator& calculator, const std::string& name)
	 : Operation (calculator, name) {}

};

#endif
