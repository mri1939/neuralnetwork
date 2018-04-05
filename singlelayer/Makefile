all: singlelayer.o main.o
	mkdir bin
	gcc -Wall -o bin/testsingle singlelayer.o main.o -lblas -lm

singlelayer.o: singlelayer.c singlelayer.h
	gcc -Wall -c singlelayer.c

main.o: main.c singlelayer.h singlylinkedlist.h
	gcc -Wall -c main.c

clean:
	rm -rf bin
	rm singlelayer.o main.o
