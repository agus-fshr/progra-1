calcu: main.o operations.o calc_front.o
	gcc main.o operations.o calc_front.o -o calcu -Wall

main.o: main.c operations.h calculator_front.h
	gcc -c main.c -o main.o -Wall

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o -Wall

calc_front.o: calculator_front.c calculator_front.h
	gcc -c calculator_front.c -o calc_front.o -Wall

clean:
	rm *.o