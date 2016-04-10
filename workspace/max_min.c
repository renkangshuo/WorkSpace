#include<stdio.h>
#define N 4
int main(int argc, const char *argv[])
{
    int i, j;
    int max_i, max_j;
    int min_i, min_j;
    int a[N][N] = {{1, 2, 3, 4},
                    {4, 5, 6, 5},
                    {7, 8, 9, 10},
                    {11, 12, 13, 14}};
    int max, min;
    max = 0;
    min = 100;
    int count = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            if (a[i][j] > max)
            {
                max_i = i;
                max_j = j;
                max = a[i][j];
            }
        }
        for (int k = 0; k < N; k++)
        {
            if (a[k][max_j] < min)
            {
                min = a[k][max_j];
                min_i = k;

            }
        }
        if (max_i == min_i){
            count++;
            printf("Found one: %d\n", a[max_i][max_j]);
        }


    }

    return 0;
}
