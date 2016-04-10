#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE* write_fp;
	char buffer[BUFSIZ + 1];

	sprintf(buffer, "Once upon a time, there was...\n");
	write_fp = popen("od -c", "w");

	if (write_fp != NULL) {
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		printf("%d\n", EXIT_SUCCESS);
		printf("%d\n", EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
