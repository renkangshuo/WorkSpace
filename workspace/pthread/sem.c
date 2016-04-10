#include <semaphore.h>
#include "csapp.h"

sem_t sem_read, sem_write;

// write from terminal
void *func1(void *arg1)
{
	ssize_t n;
	char buf[10];
	int fd1 = *((int *)arg1);
	while ( 1 ) {
		sem_wait(&sem_write);
		
		while ( (n = read(1, buf, 10)) > 0 ) {
			write(fd1, buf, n);
		}

		sem_post(&sem_read);

	}
}
// read into terminal
void *func2(void *arg2)
{
	int fd2 = *((int *)arg2);
	ssize_t n;
	char buf[10];
	
	while ( 1 ) {
		sem_wait(&sem_read);
		while ( (n = read(fd2, buf, 10)) > 0) {
			write(0, buf, n);
		}

		sem_post(&sem_write);

	}
}
	

int main(int argc, const char *argv[])
{
	int ret;

	int fd1, fd2;
	pthread_t td1, td2;

	sem_init(&sem_write, 0, 1);
	sem_init(&sem_read, 0, 0);

	fd1 = open("1.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	fd2 = open("1.txt", O_RDONLY);

	ret = pthread_create(&td1, NULL, func1, (void *)&fd1);

	if(ret == -1)
	{
	}

	ret = pthread_create(&td2, NULL, func2, (void *)&fd2);

	if (ret == -1)
	{
	}


	pthread_exit(NULL);
	return 0;
}
