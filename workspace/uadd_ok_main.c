#include<stdio.h>


int uadd_ok(unsigned short, unsigned short);
int main() {
    unsigned short x;
    unsigned short y;
    x = 12340;
    y = 21356;
    printf("%d\n", uadd_ok(x, y));
}


