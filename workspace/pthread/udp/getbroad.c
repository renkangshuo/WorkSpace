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
	char buf[N];
	struct sockaddr_in myaddr, peeraddr;
	socklen_t peerlen = sizeof(peeraddr);

	if (argc < 3) {
		printf("Usage: <%s> <ip> <port>\n", argv[0]);
		return -1;
	}
	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) 
	{
		perror("Fail tp socket");
		return -1;
	}

	bzero(&myaddr, sizeof(myaddr));
	myaddr.sin_family =  PF_INET;
	myaddr.sin_port = htons(atoi(argv[2]));

	myaddr.sin_addr.s_addr = inet_addr(argv[1]);
	if (bind(sockfd, (SA *)&myaddr, sizeof(myaddr)) < 0)
	{
		perror("fail to bind");
		exit(-1);
	}

	while (1) {
		recvfrom(sockfd, buf, N, 0 ,NULL, NULL);
		printf("%s\n", buf);

	}

	
	return 0;
}
