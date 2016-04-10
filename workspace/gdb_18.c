#include<stdio.h>

/* add: add number from 1 to m */
int add1(int m) {
    int i, n = 0;
    for (i = 1; i <= m; i++)
        n += i;
    printf("The sum of 1-%d in add is %d\n", m, n);
}

int main() {
    int i, n =0 ;
    add1(50);
    for (i = 1; i <= 50; i++)
        n += i;
    printf("The sum of 1-50 is %d \n", n);
}
