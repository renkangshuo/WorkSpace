#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd;
	fd = open("./2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);

	fputc('a', fp);

	fseek(fp, 10, SEEK_CUR);
	fputc('b', fp);

	return 0;
}
