#include "csapp.h"

#define N 128

void sigchld_handler(int sig)
{
	while (waitpid(-1, 0, WNOHANG) > 0)
		;
	return;
}

int main(int argc, const char *argv[])
{
	int fd;
	int listenfd, connfd, port, clientlen;
	char buf[N];
	int n = 0;
	struct sockaddr_in clientaddr;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);
	listenfd = open_listenfd(port);

	Signal(SIGCHLD, sigchld_handler);

	bzero(buf, N);
	clientlen =  sizeof(clientaddr);

	while (1) {
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		printf("Connected one\n");

		if (Fork() == 0) {
			Close(listenfd); /* Child closes its listening socket */

			while ((n = read(connfd, buf, N)) > 0)
			{
				if (strncmp(buf, "quit", 4) == 0)
					break;
				printf("%s", buf);
				write(connfd, buf, n);
			}
			Close(connfd);
			exit(0);
		}
		Close(connfd); /* Parent closes connected socket */  // important
	}
	exit(0);
}
