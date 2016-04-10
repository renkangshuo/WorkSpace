#include<stdio.h>

void psum(float a[], float[], long int n)
{

    long int i;
    p[0] = a[0];
    for (i = 1; i < n - 1; i += 2) {
        float mid_val = p[i-1] + a[i];
        p[i]    = mid_val;
        p[i+1]  = mid_val + a[i+1];
    }

    /* For even n, finish remaining element */
    if (i < n)
        p[i] = p[i-1] + a[i];
}
