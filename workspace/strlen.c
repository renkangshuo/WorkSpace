#include<stdio.h>

int main(int argc, const char *argv[])
{
    char *s = "123";
    int count = 0;
    while (*s++)
        count++;
    printf("%d\n", count);
    return 0;
}
