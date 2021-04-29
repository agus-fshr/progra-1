CC := gcc 
OPTIONS = -O2 -g -Wall   # -g for debug, -O2 for optimise and -Wall additional messages
OBJS = hellomake.o hellofunc.o
SRC =  hellomake.c hellofunc.c 
HEADERS = hellofunc.h

hellomake:${OBJS}
#	gcc hellomake.o hellofunc.o -o hellomake
	${CC} ${OPTIONS} ${OBJS} -o hellomake

#  la opción -c no genera el ejecutable, sino el código objeto
#  (compilo No link-edito )
${OBJS}: ${SRC}  ${HEADERS} 
	${CC} ${OPTIONS} -c ${SRC}
clean:
	rm *.o
