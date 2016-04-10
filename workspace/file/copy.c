#include<stdio.h>
#include<string.h>
#include<errno.h>

int main(int argc, const char *argv[])
{
	FILE *sp;
	FILE *dp;

	int c;

	if (argc < 3) {
		printf("Usage: source file <> desitination file>\n");
		return -1;
	}

	if ( (sp = fopen(argv[1], "r") ) == NULL ) {
		fprintf(stderr, "fail to open file %s : %s", argv[1], strerror(errno));
		printf("\n");
		return -1;
	}

	if ( (dp = fopen(argv[2], "w") ) == NULL ) {
		fprintf(stderr, "fail to open file %s : %s", argv[2], strerror(errno));
		printf("\n");
		return -1;
	}

	while( (c = fgetc( sp ) ) != EOF && feof( sp ) == 0) {
		if ( (fputc( c, dp ) ) == EOF ) {
			fprintf(stderr, "error\n");
			return -1;
		}

	}

	fclose(sp);
	fclose(dp);


	return 0;
}
