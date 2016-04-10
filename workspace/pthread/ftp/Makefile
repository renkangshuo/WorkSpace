all: ser cli clean

ser:ftpser.o csapp.o 
	gcc ftpser.o csapp.o -o ser -l pthread

cli:ftpcli.o csapp.o
	gcc ftpcli.o csapp.o -o cli -l pthread

ftpser.o:csapp.h

ftpcli.o:csapp.h

csapp.o:csapp.h

clean:
	-rm *.o
