#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE* read_fp;
	char buffer[BUFSIZ + 1];
	int chars_read;
	memset(buffer, '\0', sizeof(buffer));
	read_fp = popen("ps ax", "r");
	if (read_fp != NULL) {
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while (chars_read > 0) {
			buffer[chars_read - 1] = '\0';
			printf("Reading %d:-\n %s \n", BUFSIZ, buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		printf("%d\n", EXIT_SUCCESS);
		exit(EXIT_SUCCESS);
	}

	return 0;
}
