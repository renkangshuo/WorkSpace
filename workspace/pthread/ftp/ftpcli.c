#include "csapp.h"

#define N 8096
int main(int argc, const char *argv[])
{
	int fd;
	int clientfd, port;
	char buf[N];
	char buf1[N];
	char *host;
	int n = 0;
	int ret;
	char filename[20];
	long file_size = 0;

	if (argc != 4) {
		fprintf(stderr, "usage: %s <host> <port> <filename>\n", argv[0]);
		exit(0);
	}

	fd = Open(argv[3], O_CREAT | O_WRONLY | O_TRUNC , 0664);

	host = argv[1];
	port = atoi(argv[2]);

	clientfd = Open_clientfd(host, port);
	printf("Connected\n");
	bzero(buf, N);
	bzero(filename, 20);
	bzero(buf1, N);

	while (1) {
		ret = recv(clientfd, buf, N, 0);

		if (ret  == 0) {
			break;
		}

		file_size += strlen(buf);

		printf("got %d bytes \n", strlen(buf));
		write(fd, buf, strlen(buf));
		printf("write in  %d bytes\n", strlen(buf));

		bzero(buf, N);
	}


	printf("Total size of the file  is %ld bytes\n", file_size);


	Close(clientfd);
	Close(fd);
	exit(0);
}
