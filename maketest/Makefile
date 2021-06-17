all: process1.o process2.o input.o output.o main.o
	gcc process1.o process2.o input.o output.o main.o -o salida.exe

main.o: main.c process1.h input.h output.h
	gcc -c main.c -o main.o

input.o: input.h input.c process2.h list.h
	gcc -c input.c -o input.o
	
output.o: output.h output.c
	gcc -c output.c -o output.o

process1.o: process1.h process1.c
	gcc -c process1.c -o process1.o

process2.o: process2.h process2.c list.h
	gcc -c process2.c -o process2.o
clean: 
	rm *.o
