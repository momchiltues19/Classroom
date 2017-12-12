#include "negate.hpp"

void Negate::eval()
{
	double value = calculator_.pop();
	calculator.push(-value);
}
