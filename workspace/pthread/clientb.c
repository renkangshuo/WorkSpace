#include "csapp.h"
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TYPEA 100
#define TYPEB 200
#define N 64
#define SIZe 64

typedef struct {
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
	msgid = msgget(key, IPC_CREAT | 0664);

	if (msgid == -1)
	{
		perror("msgget");
		exit(1);
	}

	pid = fork();

	if (pid == -1)
	{
	}
	else if (pid == 0)
	{
		while (1)
		{
			printf("Input something:\n");
			fgets(mymsg.buf, N, stdin);

			mymsg.type = TYPEB;
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
			msgrcv(msgid, &mymsg, N, TYPEA, 0);

			if (strncmp(mymsg.buf, "quit", 4) == 0)
			{
				kill(pid, SIGKILL);
				wait(NULL);

				msgctl(msgid, IPC_RMID, NULL);
				exit(0);
			}
			printf("recv from clienb.c%s\n", mymsg.buf);
		}
	}
	return 0;
}
