#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define N 64

int main(int argc, const char *argv[])
{
	time_t time_s;
	FILE* fp;
	char *sp;

	if (argc < 2) {
		printf("Usage: %s <filename>\n", argv[0]);
		return -1;
	}

	fp = fopen(argv[1], "w+");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}

	while ( 1 ) {
		time( &time_s );
		fprintf(fp, "%s\n", sp = ctime( &time_s ) );
		fprintf(stdout, "%s\n",sp = ctime( &time_s ) );
		fflush(fp);

		sleep( 1 );
	}

	return 0;
}
