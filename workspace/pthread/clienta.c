#include "csapp.h"
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/ipc.h>

#define TYPEA 100
#define TYPEB 200
#define SIZE 64
#define N 64
typedef struct 
{
	long type;
	char buf[N];
}MSG;

int main(int argc, const char *argv[])
{
	key_t key;
	key = ftok(".", 'a');

	int msgid;
	pid_t pid;
	MSG mymsg;
	printf("1\n");
	msgid = msgget(key, IPC_CREAT | 0664);
	printf("2\n");

	if (msgid == -1) 
	{
		perror("msgget");
		exit (1);
	}

	if ((pid = fork()) == 0)
	{
		while (1) 
		{
			printf("Input something:\n");
			fgets(mymsg.buf, N, stdin);

			mymsg.type = TYPEA;
			msgsnd(msgid, &mymsg, N, 0);

			if (strncmp(mymsg.buf, "quit", 4) == 0)
			{
				kill(getppid(), SIGKILL);
				//msgctl(msgid, IPC_RMID, NULL);

				exit(0);
			}
		}
	}else{
		
		while (1) 
		{
			printf("father\n");
			msgrcv(msgid, &mymsg, N, TYPEB, 0);

			if (strncmp(mymsg.buf, "quit", 4) == 0)
			{
				kill(pid, SIGKILL);

				wait(NULL);

				msgctl(msgid, IPC_RMID, NULL);
				exit(0);
			}

			printf("recv from clienta.c %s\n", mymsg.buf);
		}
	}
	printf("pid error\n");
	return 0;
}
