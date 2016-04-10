#include<stdio.h>
#include<string.h>

int main(int argc, const char *argv[])
{
    char s[] = "Welcome";
    char *p = NULL, *q = NULL, t;

    printf("%s\n", s);

    p = s;
    q = s + strlen(s) - 1;

    while (p < q){
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
    printf("%s\n", s);

    return 0;
}
