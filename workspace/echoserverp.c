#include "need.h"
#include <stdio.h>

void echo(int connfd);

void sigchld_handler(int sig) {
	while (waitpid(-1, 0, WNOHANG) > 0)
		;
	return ;
}

int main(int argc, char **argv) {
	int listenfd, connfd, port;
	socklen_t clientlen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		exit(0);
	}
	port = atoi(argv[1]);

	Signal(SIGCHLD, sigchld_handler);
	listenfd = Open_listenfd(port);

	while(1) {
		printf("Waiting for connection\n");
		connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);

		printf("Connected one\n");

		if (Fork() == 0) {
			Close(listenfd);/* Child closes its listening socket */
			echo(connfd);
			printf("Bye\n");
			Close(connfd);
			exit(0);
		}
		Close(connfd); 	/* Parent closes connected socket (important) */
	}
}
