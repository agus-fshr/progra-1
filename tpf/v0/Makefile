frogger: main.o Frog.o Level.o Lane.o
	gcc main.o Frog.o Level.o Lane.o -o frogger `pkg-config allegro-5 allegro_font-5 allegro_primitives-5 --libs --cflags` -g

main.o: main.c objects/Lane.h
	gcc -c main.c -o main.o

Frog.o: objects/Frog.c objects/Frog.h libs/position.h
	gcc -c objects/Frog.c -o Frog.o

Lane.o: objects/Lane.c objects/Lane.h
	gcc -c objects/Lane.c -o Lane.o

Level.o: objects/Level.c objects/Level.h objects/Frog.h objects/Lane.h
	gcc -c objects/Level.c -o Level.o

clean:
	rm *.o