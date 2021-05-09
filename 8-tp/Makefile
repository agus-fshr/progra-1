calcu: main.o operations.o
	gcc main.o operations.o -o calcu -Wall -Wextra

main.o: main.c operations.h
	gcc -c main.c -o main.o -Wall -Wextra

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o -Wall -Wextra

clean:
	rm *.o