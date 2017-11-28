#include <iostream>
#include <string>
#include <list>

using namespace std;

class Employee
{
protected:
	string name_;
	long id_;
public:
	Employee()
	: name_("default")
	{
		cout << "def" << endl; 
	}
	Employee(const string& name, long id)
	: name_(name),
	  id_(id)
	{}

	const string& get_name() const
	{
		return name_;
	}
	
	long get_id() const
	{
		return id_;
	}

	void print() const
	{
		cout << "Employee - " << name_ << ": " << id_ << endl;
	}
};

class Manager: public Employee //public inheritance
{
	int level_;
public:
	Manager(const string& name,  int id, int level)
	: Employee(name,id),
	  level_(level)
	{}

	int get_level() const
	{
		return level_;
	}
	
	void print() const
	{
		//Employee::print();   //able to do that
		cout << "Manager - " << name_ << ": " << id_ << ", " << level_ << endl;
	}
};

int main()
{
	Employee e1("Ivan", 1234);
	//e1.print();

	Manager m1 = Manager("Peter", 99999, 1);
	//m1.print(); //inherited from Employee; ability to overwrite

	list<Employee*> employees;
	employees.push_back(&e1);
	employees.push_back(&m1);
	
	for(list<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
	{
		cout << (*it) -> get_name() << ": " << (*it) -> get_id() << endl;
		(*it) -> print(); 
	}
	return 0;
}
