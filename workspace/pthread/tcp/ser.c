#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct message {
	int type;
	char message[24];
};

int main(int argc, const char *argv[])
{
	int listenfd, connfd;
	struct sockaddr_in seraddr;
	struct sockaddr_in clientaddr;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(50000);

	int len = sizeof(clientaddr);
	bzero(&clientaddr, len);
	
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("fail to socket");
		return -1;
	}

	if (bind(listenfd, (struct sockaddr*)&seraddr, sizeof(seraddr)) < 0)
	{
		perror("fail to bind");
		return -1;
	}

	listen(listenfd, 5);
	char buf[128];
	bzero(buf, 128);

	int ret;

	struct message msg_get;

	while (1) {
		if ((connfd = accept(listenfd, (struct sockaddr*)&clientaddr, &len)) < 0)
		{
			perror("fail to accept");
			return -1;
		}

		while (1) {
			ret = recv(connfd, &msg_get, sizeof(msg_get), 0);
			if (ret == 0)
			{
				break;
			}

			if (ret < 0)
			{
				close(connfd);
				close(listenfd);
				return -1;
			}

			printf("%d %s\n", msg_get.type, msg_get.message);

			msg_get.type++;
			send(connfd, &msg_get, sizeof(msg_get), 0);

			}

		close(connfd);
	}
	return 0;
}
