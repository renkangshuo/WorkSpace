#include "csapp.h"

typedef struct {
	int maxfd;
	fd_set read_set;
	fd_set ready_set;
	int nready;
	int maxi;
	int clientfd[FD_SETSIZE];
	rio_t clientrio[FD_SETSIZE];
} pool;

void init_pool(int listenfd, pool* p);
void add_client(int connfd, pool* p);
void check_clients(pool *p);

int byte_cnt = 0;


int main(int argc, const char *argv[])
{
	int listenfd, connfd, port;
	socklen_t clientlen = sizeof(struct sockaddr_in);
	struct sockaddr_in clientaddr;
	static pool pool;

	if (argc != 2)
	{
		printf("Usage: <port>\n");
		exit(0);
	}

	port = atoi(argv[1]);

	listenfd = Open_listenfd(port);
	init_pool(listenfd, &pool);
	while (1) {
		/* Wait for listening/connected descriptor to become ready */
		pool.ready_set = pool.read_set;
		pool.nready = Select(pool.maxfd + 1, &pool.ready_set, NULL, NULL, NULL);

		/* If listening descriptor ready , add new client to pool */
		if (FD_ISSET(listenfd, &pool.ready_set)) {
			printf("connected\n");
			connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
			add_client(connfd, &pool);
		}

		/* Echo a text line from each ready connected descriptor */
		check_clients(&pool);
	}
}

void init_pool(int listenfd, pool *p)
{
	/* Initially , there are no connected descriptor */
	int i;
	p->maxi = -1;
	for (i = 0; i < FD_SETSIZE; i++)
		p->clientfd[i] = -1;


	/* Initially, listenfd is only member of Select read set */
	p->maxfd = listenfd;
	FD_ZERO(&p->read_set);
	FD_SET(listenfd, &p->read_set);
}


void add_client(int connfd, pool *p)
{
	int i;
	p->nready--;
	for (i = 0; i < FD_SETSIZE; i++) /* find an available slot */
		if (p->clientfd[i] < 0) {
			/* Add connected descriptor to the pool */
			p->clientfd[i] = connfd;
			Rio_readinitb(&p->clientrio[i], connfd);

			/* Add the descriptor to descriptor set */
			FD_SET(connfd, &p->read_set);

			/* Update max descriptor and pool highwater mark */
			if (connfd > p->maxfd)
				p->maxfd = connfd;
			if (i > p->maxi)
				p->maxi = i;
			break;
		}
	if (i == FD_SETSIZE) /* Couldn't find an empty slot */
		app_error("add_client error: Too many clients ");
}

void check_clients(pool *p)
{
	int i, connfd, n;
	char buf[MAXLINE];
	rio_t rio;

	for (i = 0; (i <= p->maxi) && (p->nready > 0); i++) {
		connfd = p->clientfd[i];
		rio = p->clientrio[i];

		/* If the descriptor is ready, echo a text line from it */
		if ((connfd > 0) && (FD_ISSET(connfd, &p->read_set))) {
			p->nready--;
			if ((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
			{
				printf("Server received ");
				Rio_writen(connfd, buf, n);
			}
			/* EOF detected, remove descriptor from pool */
			else {
				Close(connfd);
				FD_CLR(connfd, &p->read_set);
				p->clientfd[i] = -1;
			}
		}
	}
}
