#include "csapp.h"

int global = 100;

void *fun1(void *arg)
{
	while(1)
	{
		printf("fun1:global = %d\n", global);
		sleep(1);
	}
}

void *fun2(void *arg)
{
	int i;

	int a = *((int *)arg);

	for (i = 0; i < 5; i++)
	{
		printf("fun2:global = %d, a = %d\n", global, a);
		sleep(1);
	}
}

int main(int argc, const char *argv[])
{
	int ret;
	int value = 10;
	pthread_t tid1, tid2;

	ret = pthread_create(&tid1,NULL, fun1, NULL);
	if (ret == -1)
	{
	}

	ret = pthread_create(&tid2, NULL, fun2, (void *)&value);
	if(ret == -1)
	{
	}

	pthread_join(tid2, NULL);

	printf("end\n");
	return 0;
}
