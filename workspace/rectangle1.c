#include<stdio.h>
int main(int argc, const char *argv[])
{
    int a[8][8];

    int i , j;
    i = j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
        {
            if ( i == j) 
                a[i][j] = 1;
            else if (j > i)
                a[i][j] = 0;
            else if (j == 0)
                a[i][j] = 1;
            else if (i > j && j > 0)
                a[i][j] = a[i-1][j] + a[i-1][j-1];
        }
    }

                
    for (i = 0; i < 8; i++) {

        for (j = 0; j < 8; j++) {
            printf("%5d", a[i][j]);
        }

        printf("\n");
    }
            







    return 0;
}
