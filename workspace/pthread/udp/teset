#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 64
typedef struct sockaddr SA;

int main(int argc, const char *argv[])
{
	int sockfd;
	char buf[N] = "This is a broadcase package\n";
	int on  = 1;

	struct sockaddr_in dstaddr;
	if (argc < 3)
	{
		printf("Usage : <%s> <ip> <port>\n", argv[0]);
		return -1;
	}

	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("Fail to socket");
		exit(-1);
	}

	bzero(&dstaddr, sizeof(dstaddr));
	dstaddr.sin_family = PF_INET;
	dstaddr.sin_port = htons(atoi(argv[2]));
	dstaddr.sin_addr.s_addr = inet_addr(argv[1]);



	if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) < 0)
	{
		perror("Fail to setsockopt");
		exit(-1);
	}

	while ( 1 ) {
		sendto(sockfd, buf, N, 0, (SA *)&dstaddr, sizeof(dstaddr));
		sleep(1);
	}
			
	return 0;
}
