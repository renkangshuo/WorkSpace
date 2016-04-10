#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>

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

	while (1) {
		recvfrom(socketfd, buf, 128, 0, (struct sockaddr*)&peer_addr, &len);
		printf("%s: %d, %s\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), buf);


		for (int i = 2; i < 255; i++) {

			peer_addr.sin_addr.s_addr = htonl((192<<24) + (168<<16) + (1<<8) + i);

			peer_addr.sin_port = htons(50001);

			sendto(socketfd, buf, 128, 0, (struct sockaddr*)&peer_addr, len);
		}
	}

	return 0;
}
