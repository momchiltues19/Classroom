// Nested class (Vlozhen class)
class Foo
{
public: 
	class Bar {/*...*/}; //it is not very connected to Foo; independant
private:
	Bar bar_;
	//...
};
Foo::Bar bar //iterators are nested classes

// Inline methods/functions (Vgradeni functions)
class Foo2
{
	int bar_;
public:
	int get_bar(void) const; //integration of lots of code in one place  
};

inline int Foo2::get_bar(void) const //outside function that can be used by the class
{
	//inline functions make files bigger without us realising it 	
	return bar_;
}
