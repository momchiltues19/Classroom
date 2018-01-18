all: turtle

turtle.o: turtle.cc turtle.hh

main.o: main.cc

turtle: turtle.o main.o
	g++ -o turtle turtle.o main.o

clean:
	rm -fr *.o turtle
