calcu: main.o operations.o calc_input.o
	gcc main.o operations.o calc_input.o -o calcu -Wall

main.o: main.c operations.h calculator_input.h
	gcc -c main.c -o main.o -Wall

operations.o: operations.c operations.h
	gcc -c operations.c -o operations.o -Wall

calc_input.o: calculator_input.c calculator_input.h
	gcc -c calculator_input.c -o calc_input.o -Wall

clean:
	rm *.o