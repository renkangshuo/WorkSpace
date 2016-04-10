#include <stdio.h>

#define N 10
int main(int argc, const char *argv[])
{
    int a[N], i, j , t;

    printf("Please input %d numbers\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-1-i; j++)
        {
            if (a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        for (int p = 0; p < N; p++)
            printf("%5d", a[p]);
        printf("\n");
    }

    printf("The array after sort:\n");
    for (i = 0; i < N; i++)
        printf("%5d", a[i]);
    printf("\n");
    return 0;
}
