#include <stdio.h>

int main(int argc, const char *argv[])
{
    int m = 100;
    void *p;

    p = (void *) &m;

    printf("%d %p %d %p\n", m, &m, *(int *)p, p);

    return 0;
}
