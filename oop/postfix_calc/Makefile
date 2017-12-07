all: main

point.o: point.cpp

circle.o: circle.cpp

main.o: main.cpp

main: point.o circle.o main.o
	g++ -o shapes point.o circle.o main.o

clean: 
	rm -f *.o shapes
