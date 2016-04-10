#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define CHUNK 12

int main(int argc, const char *argv[])
{
	int sfp;
	int dfp;
	size_t size = 0;
	size_t half_size = 0;
	pid_t  pid;
	char buf[CHUNK];
	int n = CHUNK;
	int sum = 0;

	sfp = open("source.txt", O_RDONLY);
	dfp = open("des.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);

	size = lseek(sfp, 0, SEEK_END); //total size
	half_size = size / 2;//half size

	if ((pid = fork()) == 0) {
		int fp = open("source.txt", O_RDONLY);
		int dfp1 = open("des.txt", O_WRONLY);
		int n = CHUNK;
		lseek(fp, half_size, SEEK_SET);
		lseek(dfp1, half_size, SEEK_SET);
		

		while( n == CHUNK ) {
			n = read(fp, buf, CHUNK);
			write(dfp1, buf, n);
		}
		close(fp);
		close(dfp1);

		exit(0);
	}

	sleep( 1 );	

	lseek(sfp, 0, SEEK_SET);

	if (half_size <= CHUNK)
	{
		read(sfp, buf, half_size);
		write(dfp, buf, half_size);
		wait();
		return 0;
	}else {
		while( 1 ) {
			read(sfp, buf, n);
			write(dfp, buf, n);

			sum += n;	
			if ((half_size - sum) < CHUNK) {
				n = read(sfp, buf, (half_size-sum));
				write(dfp, buf, n);
				break;
			}

		}
		wait();
		printf("Done.\n");

	}
	close(sfp);
	close(dfp);

	



	return 0;
}
