#define EOF -1
#define NULL 0
char *gets(char *s){

    int c;
    char *dest = s;
    int gotchar = 0;
    while  ((c = getchar()) != '\n' && c != EOF) {
        *dest++ = c;    /*no bounds checking */
        gotchar = 1;
    }
    *dest++ = '\0'; /* Terminate string */
    if (c == EOF && !gotchar)
        return NULL;    /* End of file or error */
    return s;
}

/* Read input line and write it back */
void echo() {
    char buf[8];
    gets(buf);
    puts(buf);

}

