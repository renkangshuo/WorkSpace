#include "csapp.h"

#define N 8096
int main(int argc, const char *argv[])
{
	int fd;
	int listenfd, connfd, port;
	int clientlen;
	char buf[N];
	int n = 0;
	struct sockaddr_in clientaddr;
	int file_size = 0;
	if (argc != 3) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);

	listenfd = open_listenfd(port);


	
	fd = Open(argv[2], O_RDONLY | O_EXCL, 0664);

	bzero(buf, N);
	printf("waiting.........\n");


	while (1) {
		clientlen =  sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		printf("Connected one\n");

		
		while ((n = read(fd, buf, N)) > 0)
		{
			file_size += n;
			write(connfd, buf, n);
		}
		printf("Total size of the file transfered is %d bytes\n", file_size);
		printf("Done!\n");
		printf("Waiting for the next one......\n");

		lseek(fd, 0, SEEK_SET);

		Close(connfd);


	}
	
	exit(0);
}
