#include <errno.h>
#include "csapp.h"
#include <sys/sem.h>
#include <sys/ipc.h>

int main(int argc, const char *argv[])
{
	key_t key1 = 12345;
	int semid;
	unsigned short semval;
	int cnt = 5;
	int childpid;

	struct sembuf wait, signal;

	wait.sem_num = 0;
	wait.sem_op = -1;
	wait.sem_flg = SEM_UNDO;

	signal.sem_num = 0;
	signal.sem_op = 1;
	signal.sem_flg = SEM_UNDO;

	semid = semget(key1, 1, IPC_CREAT | 0777);
	printf("Allocating the semaphore: %s\n", strerror(errno));

	semval = 1;
	semctl(semid, 0, SETVAL, semval);
	printf("Setting semaphore value to %d:		%s\n", semval, strerror(errno));

	semval = semctl(semid, 0, GETVAL);
	printf("Initialized Semaphore value to %d	%s\n", semval, strerror(errno));

	childpid = fork();

	if (childpid == 0) 
	{
		execl("./sem2", "./sem2", NULL);
	}

	while (cnt-- > 0) {
		semop(semid , &wait, 1);
		sleep(2);
		printf("\n\nProcess1 using the terminal now\n");
		printf("I am process 1\n");

	//
	//semctl(semid, 0, GETVAL, &semval);
		semval = semctl(semid, 0, GETVAL);
		printf("I decrease the semaphore value to : %d\n", semval);

		printf("My process id is = %d\n", getpid());
		printf("Process1 leaving the terminal now\n\n");
		semop(semid, &signal, 1);
	}

	//semctl(semid, 0, GETVAL, &semval);
	semval = semctl(semid, 0, GETVAL);
	printf("Process 1: Semaphore value after calling signal :		%d\n", semval);

	sleep(5);
	semctl(semid, 0, IPC_RMID);
	printf("Semaphore removed from the System =		%s\n", strerror(errno));
	return 0;
}
