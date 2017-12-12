#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <string>

class Operation
{
	std::string name_;

protected:
	Calculator& calculator_;

public:
	Operation(Calculator& calculator, const std::string& name)
	: calculator_(calculator), name_(name) {}

	const std::string& get_name() const 
	{
		return name_;
	}

	virtual void eval() = 0;
};

#endif
