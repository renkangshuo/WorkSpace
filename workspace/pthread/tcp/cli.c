#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

struct message {
	int type ;
	char message[24] ;
};

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
//	char buf[128];
//	bzero(buf, 128);
	if (connect(clientfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0)
	{
		perror("fail to connect");
		return -1;
	}
	struct message msg, msgb;
	msg.type = 100;
	strcpy(msg.message, "Hello World");

	while (1) {
//		gets(buf);
		send(clientfd, &msg, sizeof(msg), 0);
		//bzero(buf, 128);
		
		recv(clientfd, &msg, sizeof(msg), 0);

		printf("%d %s\n", msg.type, msg.message);
		sleep(1);
	}
	return 0;
}
