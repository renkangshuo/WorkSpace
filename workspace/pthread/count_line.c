#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int line = 0;
	char buf[128];
	FILE* fp;

	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		perror("fail to open");
		return -1;
	}

	while (fgets(buf, 128, fp) != NULL){
		if (buf[strlen(buf)-1] == '\n')
			line++;
	}

	printf("te   %d\n", line);
	
	return 0;
}
