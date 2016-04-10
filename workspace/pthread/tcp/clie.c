#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int clientfd;
	struct sockaddr_in  seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("192.168.6.171");
	seraddr.sin_port = htons(50000);

	if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		return -1;
	}

	char buf[128];
	bzero(buf, 128);
	if (connect(clientfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0)
	{
		perror("fail to connect");
		return -1;
	}

	while (1) {
		read(1, buf, 128);
		send(clientfd, buf, strlen(buf), 0);

		if (strncmp(buf, "quit", 4) == 0)
			break;
		
		bzero(buf, 128);
		recv(clientfd, buf, sizeof(buf), 0);

		printf("%s\n", buf);

		bzero(buf, 128);
	}
	printf("quit\n");
	Close(clientfd);
	return 0;
}
