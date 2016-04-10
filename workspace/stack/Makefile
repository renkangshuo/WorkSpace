all:stack clean

stack:main.o stack.o

main.o:main.c
	gcc -c -std=c99 main.c

stack.o:stack.c

clean:
	rm *.o
