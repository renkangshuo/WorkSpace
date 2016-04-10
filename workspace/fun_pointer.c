#include <stdio.h>

int test(int a, int b, int (*pFunc) (int, int));
int plus(int a, int b);
int minus(int, int);
int main(int argc, const char *argv[])
{
    int x = 5;
    int y = 8;

    int (*pFunc) (int, int);
    pFunc = plus;
    printf("%d\n", (*pFunc)(x, y));

    pFunc = minus;
    printf("%d\n", (*pFunc)(x, y));

    printf("%d\n", test(15, 5, plus));
    printf("%d\n", test(15, 5, minus));
    
    return 0;
}

int


for (isdfjidj; fsdijfidsjf    /* code */

}

