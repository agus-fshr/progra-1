porta: main.o gpio_emul.o
	gcc main.o gpio_emul.o -o porta -Wall

main.o: main.c gpio_emul.h
	gcc -c main.c -o main.o -Wall

gpio_emul.o: gpio_emul.c gpio_emul.h
	gcc -c gpio_emul.c -o gpio_emul.o -Wall

clean:
	rm *.o