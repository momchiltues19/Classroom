all: postfix

calculator.o: calculator.cpp

negate.o: negate.cpp

postfix.o: postfix.cpp

postfix: calculator.o postfix.o negate.o
	g++ -o postfix calculator.o postfix.o negate.o

clean: 
	rm -f *.o postfix
