#include <stdio.h>
int a[][5] = {{ 8, 14, 11, 2, 5},
    {5, 2, 1, 5, 99},
    {1, 2, 55, 6, 97}
};
int main(int argc, const char *argv[])
{
    int max = 0;
    int t = 0;
    for (int i = 0; i < 3; i++)
         for (int j = 0; j < 5; j ++ /* loop */)
        {
            /* code */
            if (a[i][j] > max) {
                max = a[i][j];
            }

        }
    printf("max = %d\n", max);
    
    return 0;
}
