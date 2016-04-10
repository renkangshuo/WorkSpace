#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() 
{
	int fd;
	char buf[10] = {0};
	ssize_t n;
	fd = open("./1.txt", O_RDONLY);

	if (fd == -1)
	{
		perror("open");
		return -1;
	}

	n = read(fd, buf, 10);
	buf[n - 1] = '\0';
	printf("n = %d\n", n);
	printf("%s\n", buf);
	return 0;
}
