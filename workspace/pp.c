#include<stdio.h>
int main(int argc, const char *argv[])
{
    int a[2][3] = {{1, 2, 3},
        {4, 5, 6}};
    int **p = &a;
    return 0;
}
