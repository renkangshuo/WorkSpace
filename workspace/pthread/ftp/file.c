#include "csapp.h"

int main(int argc, const char *argv[])
{
	int fd;
	char buf[128];
	bzero(buf, 128);

	fd = open("pppppp", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	fgets(buf, 128, stdin);

	write(fd, buf, strlen(buf));

	
	return 0;
}
