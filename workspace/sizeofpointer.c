#include<stdio.h>
int main(int argc, const char *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    printf("%d\n", sizeof(a));
    return 0;
}
