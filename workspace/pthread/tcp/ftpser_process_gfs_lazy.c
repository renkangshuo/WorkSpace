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
		printf("Waiting...\n");
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		printf("Connected one\n");

		if (Fork() == 0) { /*   Original Process creates its child Process */

			if (Fork() == 0) { /* Child Process creates its grandchild */
				Close(listenfd); /* GrandChild Process closes its listening socket */

				while ((n = read(connfd, buf, N)) > 0) /* GrandChild perfroms echo task */
				{
					if (strncmp(buf, "quit", 4) == 0)
						break;
					printf("%s", buf);
					write(connfd, buf, n);
					bzero(buf, sizeof(buf));
				}
				printf("This service quitting...\n");
				Close(connfd);

				exit(0);
			}
			else { /* Child Process Close its connected fd */
				Close(connfd);
				/* Child Process closes its listenfd */
				Close(listenfd);
				exit(0);
			}
		}
		else {
		Close(connfd); /* Original Process closes connected socket */  // important
		}
	}
	exit(0);
}
