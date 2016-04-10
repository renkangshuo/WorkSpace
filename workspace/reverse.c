#include <stdio.h>
#include <string.h>
#define MAXARGS 128
#define MAXLINE 128

/* Function prototypes */
int  parseline(char *buf, char **argv);

int main() {
    char cmdline[MAXLINE]; /* Command line */
    char buf[MAXLINE]; /* Holds modified command line */
    char *argv[MAXARGS];    /* Argument list execve() */
    while (1) {
        /* Read */
        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        strcpy(buf, cmdline);
        
        
        parseline(buf, argv);
    }
}
/* parseline- Parse the command line and build the argv array */
int parseline(char *buf, char **argv) {
    char *delim; /* Points to first space delimiter */
    int argc;   /* Number of args */
    

    buf[strlen(buf)-1] = ' '; /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
        buf++;

    /* Build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    
    }
    //argv[argc] == NULL;
    //int i = argc-1; 
    while (--argc >= 0)
    {
        
        printf("%s ", argv[argc]);
    }
    printf("\n");

    if (argc == 0) /* Ignore blank line */
        return 1;
    else
        return 0;
    


}
