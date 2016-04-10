all: ser cli clean

ser:ftpser2.o csapp.o 
	gcc ftpser2.o csapp.o -o ser -l pthread

cli:ftpcli2.o csapp.o
	gcc ftpcli2.o csapp.o -o cli -l pthread

ftpser2.o: ftpser2.c csapp.h

ftpcli2.o: ftpcli2.c csapp.h

csapp.o:csapp.h

clean:
	-rm *.o
