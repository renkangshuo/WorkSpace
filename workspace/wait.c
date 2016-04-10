#include<stdio.h>
#include<sys/wait.h>

pid_t wait(int *status); /* if success, return PID of child process, or -1 if error happens */

