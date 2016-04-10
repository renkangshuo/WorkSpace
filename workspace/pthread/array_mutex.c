#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

int a[5] = {1, 2, 3, 4, 5};

void *fun1(void *arg)
{
	int i;
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&cond, &mutex);

	for (i = 0; i < 5; i++)
	{
		printf("fun1:%d\n", a[i]);
		sleep(1);
	}
	pthread_mutex_unlock(&mutex);
	//pthread_cond_signal(&cond);
}

void *fun2(void *arg)
{
	int i;

	pthread_mutex_lock(&mutex);
	//pthread_cond_wait(&cond, &mutex);
	for (i = 4; i >= 0; i--)
		{
			printf("fun2:%d\n", a[i]);
			sleep(1);
		}
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond);
}

int main(int argc, const char *argv[])
{
	int ret;
	pthread_t tid[3];

	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);

	ret = pthread_create(&tid[0],NULL, fun1, NULL);
	ret = pthread_create(&tid[1], NULL,fun2, NULL);

	while(1);
	return 0;
}
