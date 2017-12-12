#ifndef NEGATE_HPP
#define NEGATE_HPP

#include "unary.hpp"

class Negate : public UnaryOperation
{

public:
	Negate(Calculator& calculator) : UnaryOperation(calculator, "neg") {}

	void eval();
};

#endif
