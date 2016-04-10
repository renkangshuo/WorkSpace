all: list clean

list:list_i.o list.o
	gcc list_i.o list.o -std=c99 -o list

list_i.o:list_i.c
	gcc -o list_i.o -c list_i.c -std=c99

list.o:list.c
	gcc -o list.o -c list.c -std=c99

clean:
	rm *.o
