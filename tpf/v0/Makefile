frogger: main.o Frog.o Mob.o Level.o render.o libs/joydisp/termlib.o
	gcc main.o Frog.o Mob.o Level.o render.o libs/joydisp/termlib.o -o frogger2

main.o: main.c objects/Frog.h objects/Level.h libs/render.h libs/joydisp/termlib.h
	gcc -c main.c -o main.o

Frog.o: objects/Frog.c objects/Frog.h libs/position.h
	gcc -c objects/Frog.c -o Frog.o

Mob.o: objects/Mob.c objects/Mob.h libs/position.h
	gcc -c objects/Mob.c -o Mob.o

Level.o: objects/Level.c objects/Level.h libs/position.h objects/Mob.h objects/Frog.h
	gcc -c objects/Level.c -o Level.o

render.o: objects/Level.h libs/position.h libs/render.h libs/render.c libs/joydisp/termlib.o libs/joydisp/disdrv.o
	gcc -c libs/render.c -o render.o

clean:
	rm *.o