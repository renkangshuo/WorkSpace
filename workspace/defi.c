#include<stdio.h>

#define MAX(a,b) (a > b) ? a:b
int main() {
    int x = 10, y = 20;
    int max = 0;
    max = MAX(x, y);
    printf("max = %d\n", max);

    return 0;
}
