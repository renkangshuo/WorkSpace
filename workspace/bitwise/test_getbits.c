#include <stdio.h>

int main(int argc, const char *argv[])
{
	unsigned x = 0x1abc5b26;

	unsigned y = 0;
	
	y = getbits(x, 4, 5);

	printf("%0x\n", y);
	return 0;
}
