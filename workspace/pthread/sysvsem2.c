#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

int main(int argc, const char *argv[])
{
	key_t key1 = 12345;
	int semid;
	unsigned short semval;
	semval = 100;
	int cnt = 5;

	struct sembuf wait, signal;

	wait.sem_num = 0;
	wait.sem_op = -1;
	wait.sem_flg = SEM_UNDO;

	signal.sem_num = 0;
	signal.sem_op = 1;
	signal.sem_flg = SEM_UNDO;

	semid = semget(key1, 1, 0777 | IPC_CREAT);
	printf("Allocating the semaphore: %s\n", strerror(errno));

	while(cnt-- > 0) {
		semop(semid, &wait, 1);
		sleep(2);
		printf("semval = %d\n", semval);
		printf("\n\nProcess2 using the terminal now\n");
		printf("I am process 2\n");

		//semctl(semid, 0, GETVAL, &semval);
		semval = semctl(semid, 0, GETVAL);
		printf("I decrease the semaphore value to: %d\n", semval);

		printf("MY process id is = %d\n", getpid());
		printf("Process2 leaving the terminal now\n\n");
		semop(semid, &signal, 1);
	}

	semval =   semctl(semid, 0, GETVAL);
	printf("Process2 : Semaphore value after calling signal :%d\n", semval);

	return 0;
}
