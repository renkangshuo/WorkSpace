#include <stdio.h>


int main(int argc, const char *argv[])
{
    char *s = "123";
    int num = 0;

    while (*s++ != '\0')
    {
        num = num * 10 + *s - '0';
    }

    printf("num = %d\n", num);

    
    return 0;
}
