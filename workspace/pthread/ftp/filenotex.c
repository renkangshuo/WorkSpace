#include "csapp.h"

int main(int argc, const char *argv[])
{
	int fd;
	fd = open(argv[1], O_RDONLY , 0664);


	if (errno == ENOENT)
		printf("No such file\n");


	return 0;
}
