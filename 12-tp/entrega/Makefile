porta: main.o gpio_emul.o gpio_interface.o
	gcc main.o gpio_emul.o gpio_interface.o -o porta -Wall

main.o: main.c gpio_emul.h
	gcc -c main.c -o main.o -Wall

gpio_emul.o: gpio_emul.c gpio_emul.h
	gcc -c gpio_emul.c -o gpio_emul.o -Wall

gpio_interface.o: gpio_interface.c gpio_interface.h
	gcc -c gpio_interface.c -o gpio_interface.o -Wall
clean:
	rm *.o