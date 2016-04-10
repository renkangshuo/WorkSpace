#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
	struct in_addr ip_addr;
	char *p;
	ip_addr.s_addr = 0x0ff0f00f;
	printf("%s\n", inet_ntoa(ip_addr));
}
