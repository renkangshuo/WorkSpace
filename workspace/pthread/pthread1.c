#include<stdio.h>
#include<pthread.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<semaphore.h>

//sem_t sem_read, sem_write;
pthread_cond_t cond;
pthread_mutex_t mutex;

void *read_file(void *file)
{
	int fd;
	ssize_t n;
	char buf[10];
	printf("read\n");
	fd = open((const char *)file, O_RDONLY | O_CREAT | O_EXCL, 0664);
	if (fd = -1)
	{
		if (errno == EEXIST) 
		{
			fd = open((const char *)file, O_RDONLY);
		}
		else
		{
			perror("open_read");
			exit(EXIT_FAILURE);
		}
	}
	
	while (1)
	{
		//sem_wait(&sem_read);
		pthread_mutex_lock(&mutex);
		pthread_cond_wait(&cond, &mutex);

		n = read(fd, buf, sizeof(buf));

		write(1, buf, n);
		//sem_post(&sem_write);
		pthread_mutex_unlock(&mutex);

	}
}

void *write_file(void *file)
{
	int fd;

	ssize_t n;
	char buf[10];
	printf("write\n");
	fd = open((const char *)file, O_WRONLY | O_CREAT | O_EXCL, 0664);
	if (fd = -1)
	{
		if (errno == EEXIST)
		{
			fd = open((const char *)file, O_WRONLY | O_TRUNC);
		}
		else{
			perror("open_write");
		}
	}

	while(1)
	{
		//sem_wait(&sem_write);
		sleep(1);
		pthread_mutex_lock(&mutex);
		n = read(0, buf, sizeof(buf));

		if (strncmp(buf, "quit", 4) == 0)
			break;

		write(fd, buf, n);

		//sem_post(&sem_read);
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}

	pthread_exit(NULL);
}

int main(int argc, const char *argv[])
{
	int ret;
	pthread_t tid1, tid2;

	//sem_init(&sem_write, 0, 1);
	//sem_init(&sem_read, 0, 0);
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL);

	ret = pthread_create(&tid1, NULL, read_file, (void *)"1.txt");

	ret = pthread_create(&tid2, NULL, write_file, (void *)"1.txt");

	pthread_join(tid2, NULL);
	return 0;
}
