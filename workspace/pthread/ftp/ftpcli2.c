#include "csapp.h"

#define N 128

struct message {
	int type;
	char buffer[N];
};

int main(int argc, const char *argv[])
{
	int fd;
	int clientfd, port;
	struct message msg;
	char filename[20];
	bzero(msg.buffer, N);
	msg.type = 0;
	char *host;
	int n = 0;
	int ret;
	long file_size = 0;

	if (argc != 4) {
		fprintf(stderr, "usage: %s <host> <port> <filename>\n", argv[0]);
		exit(0);
	}

	fd = Open(argv[3], O_CREAT | O_WRONLY | O_TRUNC , 0664);

	host = argv[1];
	port = atoi(argv[2]);
	while (1) {
		clientfd = Open_clientfd(host, port);
		printf("Connected\n");

		printf("Please input the file you want: \n");
		read(1, msg.buffer, N);
		
		msg.buffer[strlen(msg.buffer) - 1] = '\0';

		send(clientfd, &msg, sizeof(msg), 0);

		recv (clientfd, &msg, sizeof(msg), 0);
		if (msg.type == -1) {
			printf("file not exist\n");
			msg.type = 0;
			Close(clientfd);
			continue;
		}

		while (1) {
			ret = recv(clientfd,msg.buffer, N, 0);

			if (ret  == 0) {
				break;
			}

			file_size += strlen(msg.buffer);

			printf("got %d bytes \n", strlen(msg.buffer));
			write(fd, msg.buffer, strlen(msg.buffer));
			printf("write in  %d bytes\n", strlen(msg.buffer));

			bzero(msg.buffer, N);
		}

	}

	printf("Total size of the file  is %ld bytes\n", file_size);

	Close(clientfd);
	Close(fd);
	exit(0);
}
