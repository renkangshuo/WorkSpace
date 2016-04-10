#include<stdio.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void sig_handler(int sig)
{
}

struct buf {
	pid_t pid;
	char s[1024];
};

int main(int argc, const char *argv[])
{
	key_t key;
	int shmid;
	struct buf* bufp;
	pid_t pidoth;

	signal(SIGUSR1, sig_handler);

	key = ftok(".", 'o');

	shmid = shmget(key, sizeof(struct buf), 0664 | IPC_CREAT | IPC_EXCL);

	if (shmid == -1)
	{
		if (errno == EEXIST) 
		{
			shmid = shmget(key, sizeof(struct buf), 0664);
			bufp = shmat(shmid, NULL, 0);
			pidoth = bufp->pid;
			bufp->pid = getpid();
			kill(pidoth, SIGUSR1);
		}
		else 
		{

		}
	}
	else{
		bufp = shmat(shmid, NULL, 0);
		bufp->pid = getpid();
		pause();
		pidoth = bufp->pid; 
	}

	while (1) {
		pause();
		printf("%s\n", bufp->s);
		kill(pidoth, SIGUSR1);

	}
	return 0;
}
