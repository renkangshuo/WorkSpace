#include <stdio.h>

int bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

int main(int argc, const char *argv[])
{
	unsigned x = 0x000005e;

	int num = 0;
	num = bitcount(x);

	printf("The result is %d\n", num);
	return 0;
}
