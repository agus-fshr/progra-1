all: main.o helper_functions.o conway.o
	gcc main.o helper_functions.o conway.o -o game_of_life.out

main.o: main.c helper_functions.h conway.h
	gcc -c main.c -o main.o

helper_functions.o: helper_functions.h helper_functions.c
	gcc -c helper_functions.c -o helper_functions.o

conway.o: helper_functions.h conway.h conway.c
	gcc -c conway.c -o conway.o

clean:
	rm *.o