#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd;
	fd = open("test.txt", O_WRONLY);
	lseek(fd, 10, SEEK_SET);
	char buf[10];
	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'v';

	write(fd, buf, 3);

	return 0;
}
