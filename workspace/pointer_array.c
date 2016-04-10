#include<stdio.h>

int main(int argc, const char *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    p = a;
    printf("*a%d\n", *a);
    printf("*p%d\n", *p);
    return 0;
}
