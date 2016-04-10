#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char s[10];

	read(1, s, 10);

	printf("%s", s);
	return 0;
}
