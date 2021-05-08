calcu: main.o operations.o
	gcc main.o operations.o -o calcu

main.o: main.c operations.h
	gcc -c main.c -o main.o

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o