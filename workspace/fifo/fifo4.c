#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo1"
#define BUFFER_SIZE PIPE_BUF

int main(int argc, const char *argv[])
{
	int pipefd;
	int res;
	int open_mode = O_RDONLY;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read = 0;

	memset(buffer, '\0', sizeof(buffer));

	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	pipefd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d\n", getpid(), pipefd);

	if (pipefd != -1) {
		do {
			res = read(pipefd, buffer, BUFFER_SIZE);
			bytes_read += res;
		}while (res > 0);
		(void)close(pipefd);
	}
	else {
		exit(EXIT_FAILURE);
	}

	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	return 0;
}
