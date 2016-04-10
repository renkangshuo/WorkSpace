#include <stdio.h>

int main(int argc, const char *argv[])
{
	int x = -1;
	x = x >> 8;

	printf("%d\n", x);
	printf("*******************\n");
	printf("%10X\n", x);

	unsigned int y = 1;
	y = y >> 1;
	printf("%d\n", y);
	printf("********************\n");
	printf("%10X\n", y);
	return 0;
}
