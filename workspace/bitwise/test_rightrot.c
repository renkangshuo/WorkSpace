#include <stdio.h>

int main(int argc, const char *argv[])
{
	unsigned x = 0x0000005e;
	unsigned y = 0;

	y = rightrot(x, 8);

	printf("The result is %x\n", y);
	return 0;
}
