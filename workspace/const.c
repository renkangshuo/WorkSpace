#include <stdio.h>
int main() {
    int a = 1;
    int b = 2;
    const int *p = &a;
    int *ap;
    ap = p;
    *ap = 11;
    printf("%d\n", a);
}

