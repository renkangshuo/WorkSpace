#include "csapp.h"

pid_t pid;

void driver_handler_usr1(int sig)
{
	printf("let's gogogo\n");
}

void driver_handler_sigusr2(int sig)
{
	printf("stop the bus\n");
}

void seller_handler_sigusr1(int sig)
{
	printf("get the off the bus\n");
	exit(0);
}

void driver_handler_sigtstp(int sig)
{
	kill(pid , SIGUSR1);
	exit(0);
}

void seller_handler_sigint(int sig)
{
	kill(getppid(), SIGUSR1);
}

void seller_handler_sigquit(int sig)
{
	kill(getppid(), SIGUSR2);
}


int main(int argc, const char *argv[])
{
	if ((pid = fork()) == 0)
	{
		signal(SIGINT, seller_handler_sigint);
		signal(SIGQUIT, seller_handler_sigquit);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGUSR1, seller_handler_sigusr1);

		while (1);
	}

	else {
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		unix_error("signal error\n");

	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		unix_error("signal error\n");

	if (signal(SIGTSTP, driver_handler_sigtstp) == SIG_ERR)
		unix_error("singal error\n");
	}

	signal(SIGUSR1, driver_handler_usr1);
	signal(SIGUSR2, driver_handler_sigusr2);
	
	while (1);
	return 0;
}
