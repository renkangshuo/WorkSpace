#include "csapp.h"

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
	shmid = shmget(key, sizeof(struct buf),   IPC_CREAT | IPC_EXCL| 0664);
	//shmid = shmget(key, 128,  0664 | IPC_CREAT | IPC_EXCL);

	if (shmid == -1)
	{
		if (errno == EEXIST) 
		{
			shmid = shmget(key, sizeof(struct buf),    0664);
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
		read(1, bufp->s, 20);
		kill(pidoth, SIGUSR1);
		pause();
	}
	return 0;
}
