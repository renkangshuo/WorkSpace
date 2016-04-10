#include "csapp.h"

#define N 128

struct message {
	int type;
	char buffer[N];
};

int main(int argc, const char *argv[])
{
	int fd;
	int listenfd, connfd, port;
	struct message msg;
	int clientlen;
	int n = 0;

	struct sockaddr_in clientaddr;
	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);
	listenfd = open_listenfd(port);
	bzero(msg.buffer, sizeof(msg.buffer));
	msg.type = 0;

	while (1) {
		clientlen =  sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		printf("Connected one\n");

		printf("Waiting for the filename to be transfered\n");

		recv (connfd, &msg, sizeof(msg), 0);
		printf("The file you want is %s\n", msg.buffer);
		fd = open(msg.buffer, O_RDONLY , 0664);

		if (errno == ENOENT) {
			msg.type = -1;
			send(connfd, &msg, sizeof(msg), 0);

			bzero(msg.buffer, sizeof(msg.buffer));
			msg.type = 0;
			errno = 0;

			Close(connfd);
			continue;
		}
		printf("we are now starting transfering\n");

		while ((n = read(fd, msg.buffer, N)) > 0)
		{
			write(connfd, msg.buffer, n);
		}
		printf("Done!\n");
		printf("Waiting for the next one\n");

		lseek(fd, 0, SEEK_SET);

		Close(connfd);
	}
	
	exit(0);
}
