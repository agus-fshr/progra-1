test: test.o custom_printf.o
	gcc test.o custom_printf.o -o test

test.o: test.c custom_printf.h
	gcc -c test.c -o test.o -Wall

custom_printf.o: custom_printf.c custom_printf.h
	gcc -c custom_printf.c -o custom_printf.o -Wall

clean:
	rm *.o