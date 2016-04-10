#include <stdio.h>

int main(int argc, const char *argv[])
{
	FILE* fsp;
	FILE* fdp;
	int fd[2];
//	char buf[512];
	int c;

	if (argc < 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	fsp = fopen("file2", "r");
	if (fsp == NULL) {
		perror("fopen");
		return -1;
	}

	fdp = fopen(argv[1], "w");
	if (fdp == NULL) {
		perror("fopen");
		return -1;
	}

	size_t n = 8;
#if 1
	while ( n == 8 ) {
		n = fread(fd, 1, 8, fsp);
		fwrite(fd, 1, n, fdp);
	}
//	fwrite(fd, 4, n, fdp);
#endif
#if 0
	while( ( n = fread(&c, 1, 1, fsp)) == 1) {
			fwrite(&c, 1, 1, fdp);
			
	}

#endif
	fclose(fsp);
	fclose(fdp);

	
	return 0;
}
