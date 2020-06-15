CC=gcc
CCFLAGS=-I.

all : client server

client : lib.o lib.h
	$(CC) -o client lib.o client.c -lpthread $(CCFLAGS)

server : lib.o lib.h
	$(CC) -o server lib.o server.c -lpthread $(CCFLAGS)

lib.o : lib.h
	$(CC) -o lib.o -c lib.c $(CCFLAGS)

clean :
	rm client server lib.o
