#include<stdio.h>

int main(int argc, const char *argv[])
{
    int m = 100;
    int *p;

    p = &m;

    printf("%d %d\n", sizeof(m), sizeof(p));
    printf("%d %p %p %p\n", m, &m, p, &p);

    return 0;
}
