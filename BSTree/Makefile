main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

BSTree.o: BSTree.cpp BSTree.h Node.h

clean:
	rm -f main.o Node.o BSTree.o

help:
	@echo make main : make executable named main

