# Makefile

CC = gcc
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -O3
LDFLAGS =
LDLIBS =

exe: *.c
	${CC} ${CFLAGS} -c -o main.o main.c
	${CC} ${CFLAGS} -c -o bank.o bank.c
	${CC} main.o bank.o -o exe



.PHONY: clean

clean:
	rm -f *.o *.d exe

# END