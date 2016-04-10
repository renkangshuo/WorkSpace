OBJS = main.o kdb.o command.o display.o \
	   insert.o search.o files.o utils.o
CC = gcc;
CFLAGS = -Wall -O -g
edit : $(objects) 
	$(CC) $^ -o $@
main.o : main.c defs.h
	(CC) $(CFLAGS) -c $< -o $@
kdb.o : kdb.c defs.h command.h
	(CC) $(CFLAGS) -c $< -o $@
display.o : display.c defs.h buffer.h
	(CC) $(CFLAGS) -c $< -o $@
insert.o : insert.c defs.h buffer.h
	(CC) $(CFLAGS) -c $< -o $@
search.o : search.c defs.h buffer.h
	(CC) $(CFLAGS) -c $< -o $@
files.o : files.c defs.h buffer.h
	(CC) $(CFLAGS) -c $< -o $@

	



