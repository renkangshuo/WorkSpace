#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ + 1];
	pid_t fork_result;

	memset(buffer, '\0', sizeof(buffer));

	if (pipe(file_pipes) == 0) {
		fork_result = fork();
		if (fork_result == -1) {
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if (fork_result == 0) {
			sprintf(buffer, "%d", file_pipes[0]);
			(void)execl("pipe4", "pipe4", buffer, (char *)0);
			exit(EXIT_FAILURE);
		}
		else
		{
			data_processed = write(file_pipes[1], some_data, strlen(some_data));

			printf("%d - wrote %d bytes\n", getpid(), data_processed);
		}
	}
	return 0;
}
