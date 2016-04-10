#include "csapp.h"
#include <time.h>
pid_t pid;


void child_handler_sigusr1(int sig)
{
	time_t time1;
	time(&time1);
	char *time_p;
	char time[40];
	time_p = ctime(&time1);
	strcpy(time, time_p);
	time[strlen(time) - 1] = '\0';
	
	FILE* fp;
	fp = fopen("test.txt", "a+");

	FILE* fp2;
	fp2 = fopen("test.txt", "r");
	if (fp2 == NULL)
	{
		perror("fp2");
		exit(0);
	}

	char buf[128];
	int line = 0;

	while (fgets(buf, 128, fp2) != NULL) 
	{
		if (buf[strlen(buf) - 1 ] == '\n')
			line++;
	}
	printf("%s %d \n", time, line);

	fprintf(fp, "%s %d \n", time, line);
	fclose(fp); /* close the fp */

}

void child_handler_sigusr2(int sig)
{
	exit(0);
}

void child_handler_sigint(int sig)
{
	FILE* fp;
	fp = fopen("test.txt", "r");

	if (fp == NULL)
	{
		perror("fail to fopen");
		exit(0);
	}
	int n;
	n = 0;
	char buf[128];

	while (fgets(buf, 128, fp) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n') 
			n++;
	}

	printf("%d\n", n);
	fclose(fp); /* close the fp */
}

void father_handler_sigtstp(int sig)
{
	kill(pid, SIGUSR2);
	wait(NULL);
	exit(0);
}

int main(int argc, const char *argv[])
{
	if ( (pid = fork()) == 0) {
		signal(SIGUSR1, child_handler_sigusr1);
		signal(SIGUSR2, child_handler_sigusr2);
		signal(SIGINT, child_handler_sigint);
		signal(SIGTSTP, SIG_IGN);

		while (1);
	}
	else {
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, father_handler_sigtstp);

		char buf[10];
		read(1, buf, 10);
		while (1) {
			if ( strncmp (buf, "begin", 5) == 0) {
				while (1) {
					kill(pid, SIGUSR1);
					sleep(1);
				}
			}else {
				printf("wrong input\n");
				read(1, buf, 10);
			}
		}
	}

	return 0;
}
