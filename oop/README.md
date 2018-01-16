# Object Oriented Programming

## 7.11
* New teacher
### Dynamic memory - ([dynamic_stack.cpp](https://github.com/momchiltues19/Classroom/blob/masteger/oop/dynamic_stack.cpp))
* FIFO - First in First out
* LIFO - Last in First out
* static stack vs dynamic stack
* in C - malloc & free
* in C++ - **new** & **delete**
* `new Foo[10]` requires `delete [] arr1`

## 9.11 
* Discussion on the new teacher
* Continuing from where we left off
### Dynamic memory - ([copy_constructor.cpp](https://github.com/momchiltues19/Classroom/blob/master/oop/copy_constructor.cpp))
* Copying constructor

## 14.11
* Hw questions
### Double-noded(?) list and DIY iterator - ([two_list.cpp](https://github.com/momchiltues19/Classroom/blob/master/oop/two_list.cpp))

## 16.11
* Hw questions
* `char* pchar;` - pointer to char
* `const char* cpchar;` - pointer to const char
* `char* const pcharc;` - const pointer to char <- **this** falls here
* `const char *const cpcharc;` - const pointer to const char
### Post increment operator - ([two_list.cpp](https://github.com/momchiltues19/Classroom/blob/master/oop/two_list.cpp))

## 21.11
* `const Point *const func() const {}` - function that returns a constant pointer to a constant object  
### Vectors - ([2-vector.md](https://github.com/elsys/oop2017-2018/blob/master/practice/2-vector.md))

## 28.11
*  inheritance part two, you can see part one in [stephan's classroom repo](https://github.com/stefan50/classroom/blob/master/inheritance.cpp)

## 30.11
* In Жife you don't choose what prog language you are gonna use :,(
### Makefile - ([makefile](https://github.com/momchiltues19/Classroom/blob/master/oop/makefile))
* Since UNIX came to be(_Някога, много отдавна, people were still lazy THE END_)

## 5.12
* virtual method aka the thing we using in [shape.cpp](https://github.com/momchiltues19/Classroom/master/oop/shape.cpp)
```C++
class Shape
{
	//print(); <- if it is not virtual, we always call it, not it's redefinition 	
	virtual print() = 0;
};

class Circle : public Shape
{
	print();
};

int main()
{
	Shape& s = Circle();
	Shape* sp = &s;
	list<Shape*>.shapes; 
	//Circle& c = Shape(); <- Wrong, because Circle can have things that Shape doesn't 
}
```
### Makefile 
* all - typically we use this to call all of the things we want to do(naming convention; not pre-defined)
* point.o, circle.o, main.o - .o stands for output, we use it to name the executables for the programs we want to compile
* main - here we call the ".o"s and compile them, in this case with the "shapes" as the name of the executable 
* clean - remove the executables
### Defining lists
list<Employee> e; //doesn't work that well, you can't use Manager
list<Employee*> e2; //works fine

## 7.12 
* makaroni is not a good name for any variable
* "На тия две верно решени задачи, какво повече мога да напиша, от две"
* grading is not clear at all
### Postfix calculator

## 12.12
* inline examples ([more here](https://github.com/momchiltues19/Classroom/blob/master/oop/nested_and_inline.cpp))
```C++
class Calc
{
	//...
	void run();
	//...
};
//inline void Calc::run() {}
void Calc::run()
{
	//...
}
```
### Postfix calculator
* __Meow__

## 14.12
* postfix...again...

## 19.12
* Makefiles are important
```
example.o: example.cc example.hh inherit.hh
example.o: example.cc 
```
* Makefiles make when there is a change in the said files, so it is best to also include headers
### Macro

## 4.01
* Talking about things we don't know

## 11.01
### QUEENS
```
QUEENS 
~ ~ 1 ~ | 1 ~ ~ ~ ~
1 ~ ~ ~ | ~ ~ ~ 1 ~
~ ~ ~ 1 | ~ 1 ~ ~ ~
~ 1 ~ ~ | ~ ~ ~ ~ 1 
_______ | ~ ~ 1 ~ ~
~ 1 ~ ~ |__________
~ ~ ~ 1 | 0 0 0 0 0 0
1 ~ ~ ~ | 0 0 0 0 0 0
~ ~ 1 ~ | 0 0 0 0 0 0
		| 0 0 0 0 0 0
		| 0 0 0 0 0 0
		| 0 0 0 0 0 0
you have to put an A number of queens in an AxA grid, so that none of them beat one another
```

## 16.01
