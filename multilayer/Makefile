all: multilayer.o main.o
	mkdir bin
	gcc -Wall -o bin/testmlp multilayer.o main.o -lblas -lm

multilayer.o: multilayer.c multilayer.h
	gcc -Wall -c multilayer.c

main.o: main.c multilayer.h
	gcc -Wall -c main.c

clean:
	rm -rf bin
	rm multilayer.o main.o
