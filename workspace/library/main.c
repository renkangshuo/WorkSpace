#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a, b;
	a = 1;
	b = 3;
	int sum = 0;
	sum = add(a, b);

	printf("The sum is %d\n", sum);

	return 0;
}
