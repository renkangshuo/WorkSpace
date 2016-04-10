#include<stdio.h>

#define IS_CURCLE 1
int main() {
    float c = 2, r, s;
#if IS_CURCLE
    r = 3.1415 * c * c;
    printf("area of round is: %f\n", r);
#else
    s = c * c;
    printf("area of square is: %f\n", s);
#endif

    return 0;
}
