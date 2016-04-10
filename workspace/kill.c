#include "csapp.h"

int main() {
    pid_t pid;

    /* Child sleeps until SIGKILL signal received , then dies */
    if ((pid = Fork()) == 0) {
        
        printf("control should never reach here!\n");
        pause();
        exit(0);

    }

    /* Parent sends a SIGKILL signal to a child */
    kill(pid, SIGKILL);
    exit(0);
}
