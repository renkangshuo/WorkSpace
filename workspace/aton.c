#include <stdio.h>
#include <arpa/inet.h>

/* Internet address structure */
//struct in_addr {
//	unsigned int s_addr; /* Network byte order (big-endian) */
//}

int main (int argc, char **argv) {
	struct in_addr ip_addr;

	if (argc != 2)
		printf("Usage: decimal string please\n");

	if (inet_aton(argv[1], &ip_addr) == 0) {
		printf("Error\n");
		return 0;
	}

	printf("The result is0x%08x\n", ip_addr.s_addr);


	return 0;

	
}
