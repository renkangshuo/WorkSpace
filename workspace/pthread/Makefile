all:hello clean

CC = gcc

INCLUDE = .

CFLAGS = -Wall  -lpthread -g


hello:hello.o csapp.o
	$(CC) -o hello hello.o csapp.o  $(CFLAGS)

hello.o:hello.c csapp.h
	$(CC)  -I$(INCLUDE)  -c hello.c 

csapp.o:csapp.c csapp.h
	$(CC)  -I$(INCLUDE)  -c csapp.c 

clean:
	rm *.o
