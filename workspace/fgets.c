#include <stdio.h>

int main(int argc, const char *argv[])
{
	char s[5];

	fgets(s, 5, stdin);

	//printf("%s", s);
	fputs(s, stdout);
	return 0;
}
