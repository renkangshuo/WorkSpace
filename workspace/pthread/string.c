#include "csapp.h"

void *func(void * arg)
{
	char *s;
	s = (char *)arg;
	printf("%s\n", (char *)arg);

	exit(0);
}

int main(int argc, const char *argv[])
{
	char* s = "abcde";
	char *p;
	p = s;
	int ret;
	pthread_t tid;

	ret = pthread_create(&tid, NULL, func, (void *)p);

	pthread_exit(NULL);
	return 0;
}
