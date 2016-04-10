#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int socketfd;

	int on = 1;

	char buf[128];
	bzero(buf, 128);

	struct sockaddr_in addr, peer_addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(50000);
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	bzero(&peer_addr, sizeof(peer_addr));

	int len = sizeof(peer_addr);

	if ((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket: ");
		return -1;
	}

	if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind");
		return -1;
	}

int flag;
	flag = fcntl(0, F_GETFL);
	flag |= O_NONBLOCK;
	fcntl(0, F_SETFL, flag);

	

	char s[20];
	bzero(s, 20);


	while(1){
/*		if ( -1 ==recvfrom(socketfd, buf, 128, 0, (struct sockaddr*)&peer_addr, &len)){
			if (errno != EAGAIN)
			{
				perror("fail to recvfrom");
				return -1;
			}
		}
		printf("%s: %d : %s\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), buf);
		sleep(1);
		bzero(buf, sizeof(buf));
		bzero(&peer_addr.sin_addr, sizeof(peer_addr.sin_addr));
		bzero(&peer_addr.sin_port, sizeof(peer_addr.sin_port));
		*/

		//fgets(s, 20, stdin);
		read(0, s, 20);
		printf("fgets: %s\n", s);
		bzero(s, 20);
		printf("jl\n");
		sleep(1);

	}

	return 0;
}
