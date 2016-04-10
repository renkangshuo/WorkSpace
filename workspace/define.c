#include<stdio.h>

#define M (y + 3)
int main() {
    int s, y;
    printf("Input s number: ");
    scanf("%d", &y);

    s = 5 * M;
    printf("s = %d\n", s);

    return 0;
}
