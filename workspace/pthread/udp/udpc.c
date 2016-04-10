#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

int main(int argc, const char *argv[]) 
{
	int sockfd;
	char buf[128];
	bzero(buf, 128);

	struct sockaddr_in peer_addr;
	int len = sizeof(peer_addr);

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket: ");
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(50001);
	local.sin_addr.s_addr = inet_addr("0.0.0.0");

	
	bind(sockfd, (struct sockaddr*)&local, sizeof(local));


	while (1) {
		
		recvfrom(sockfd, buf, 128, 0, (struct sockaddr*)&peer_addr, &len);
		printf("%s: %d, %s\n", inet_ntoa(peer_addr.sin_addr), ntohs(peer_addr.sin_port), buf);
	}


}
