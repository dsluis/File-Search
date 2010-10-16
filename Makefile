search: main.o list.o node.o
	g++ -g -o search main.o list.o node.o
main.o: main.cpp list.h node.h
	g++ -g -c main.cpp

list.o: list.cpp list.h node.h
	g++ -g -c list.cpp

node.o: node.cpp node.h
	g++ -g -c node.cpp

clean:
	rm -f main.o list.o node.o list
