#include "csapp.h"

#define N 128

char *s;

void *thread(void *vargp) 
{
	char buf[N];
	int n;
	int fd;
	int connfd = *((int *)vargp);
	Pthread_detach(pthread_self());
	Free(vargp);
	fd = Open(s,  O_RDONLY | O_EXCL, 0664);
	while ((n = read(fd, buf, N)) > 0)
	{
		write(connfd, buf, n);
	}
	printf("Done!\n");
	printf("Waiting for the next one\n");


	Close(connfd);

	Close(fd);
	return NULL;
}
int main(int argc, const char *argv[])
{
	int fd;
	int listenfd, *connfd, port;
	socklen_t clientlen;
	pthread_t tid;
	char buf[N];
	int n = 0;
	struct sockaddr_in clientaddr;
	if (argc != 3) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);

	listenfd = open_listenfd(port);

	s = argv[2];

	bzero(buf, N);

	clientlen =  sizeof(clientaddr);
	while (1) {
		connfd = Malloc(sizeof(int));

		*connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		Pthread_create(&tid, NULL, thread, connfd);
		printf("Connected one\n");

	}
	
	exit(0);
}
