#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
	return  x ^ (~(~0 << n) << (p+1-n));
}

int main(int argc, const char *argv[])
{
	unsigned x = 0x0000005e;

	unsigned result = 0;

	result = invert(x, 4, 3);

	printf("%x\n", result);
	return 0;
}
