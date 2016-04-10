#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE* fsp;
	FILE* fdp;
	char buf[12];
	char* c;

	if (argc < 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	fsp = fopen("file1", "r");
	if (fsp == NULL) {
		perror("fopen");
		return -1;
	}

	fdp = fopen(argv[1], "w");
	if (fdp == NULL) {
		perror("fopen");
		return -1;
	}

	while((c = fgets(buf, 12, fsp)) != NULL) {
		fputs(buf, fdp);
	}

	fclose(fsp);
	fclose(fdp);

	
	return 0;
}
