#include<stdio.h>
#define N 100
char s[N];
void handle(char *);


int main() {
    while (1) {
        gets(s); 
        handle(s);
        putchar('\n');
    }
}

void handle(char s[]) {
    char *p;
    p = s;
    while(*p) {
        if (*p != ' ')
            putchar(*p);

        p++;
    }
}
