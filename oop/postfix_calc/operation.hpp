#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <string>

class Operation
{
	std::string name_;
public:
	Operation(const std::string& name)
	: name_(name) {}

	const std::string& get_name() const 
	{
		return name_;
	}

	virtual void eval() = 0;
};

#endif
