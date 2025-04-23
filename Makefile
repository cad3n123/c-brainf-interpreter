CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c stack_template.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main
