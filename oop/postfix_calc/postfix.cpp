#include <iostream>
#include "negate.hpp"

using namespace std;

int main()
{
	Calculator calc;
	calc.add_operation(new Negate(calc));
	calc.run(cin, cout);
}
