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

``````
Class Shape
{
	//print(); <- if it is not virtual, we always call it, not it's redefinition 	
	virtual print() = 0;
};

Class Circle : public Shape
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
``````
### Makefile 
* all - typically we use this to call all of the things we want to do(naming convention; not pre-defined)
* point.o, circle.o, main.o - .o stands for output, we use it to name the executables for the programs we want to compile
* main - here we call the ".o"s and compile them, in this case with the "shapes" as the name of the executable 
* clean - remove the executables
