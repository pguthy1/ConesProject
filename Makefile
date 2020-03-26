CFLAGS=-Wall -Wextra -Werror -Wpedantic
CC=clang $(CFLAGS)

all	:	cone_gen
cone_gen	:	main.o cone.o
	$(CC) -o cone_gen main.o cone.o
main.o	: main.cpp cone.h
	$(CC) -c main.cpp
cone.o : cone.cpp cone.h
	$(CC) -c cone.cpp

# Cleaning target
clean	:
	rm -rf cone_gen main.o cone.o