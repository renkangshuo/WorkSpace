#include <stdio.h>
#define NODEBUF 1

int main(int argc, const char *argv[])
{
	int i = 0;

	printf("normal\n");

#ifndef NODEBUF
	printf("if\n");
#endif
	return 0;
}
