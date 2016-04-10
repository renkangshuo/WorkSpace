#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ((~0 << (p+1)) | ~(~0 << (p-n+1)))) | ((y & ~(~0 << n)) << (p-n+1));
}

int main(int argc, const char *argv[])
{
	unsigned x = 0x1abc5b26;
	unsigned y = 0x00000cb5;
	unsigned result;

	result = setbits(x, 4, 3, y);

	printf("%x\n", result);
	return 0;
}
