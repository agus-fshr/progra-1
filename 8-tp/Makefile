calcu: main.o operations.o
	gcc main.o operations.o -o calcu -g

main.o: main.c operations.h
	gcc -c main.c -o main.o -g

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o -g

clean:
	rm *.o