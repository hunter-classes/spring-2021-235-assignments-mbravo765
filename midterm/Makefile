main: main.o Node.o mergesort.o
	g++ -o main main.o Node.o mergesort.o

tests: tests.o Node.o mergesort.o
	g++ -o tests tests.o Node.o mergesort.o

main.o: main.cpp Node.h mergesort.h

tests.o: tests.cpp doctest.h Node.h mergesort.h

Node.o: Node.cpp Node.h

mergesort.o: mergesort.cpp mergesort.h

clean:
	rm -rf main.o tests.o Node.o mergesort.o

help:
	@echo make main: make executable named main
	@echo make tests: make test suite named tests

