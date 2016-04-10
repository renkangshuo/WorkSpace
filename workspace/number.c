#include<stdio.h>

int main() {
    int i = 1234;

    int a[4];
    a[0] = i % 10;
    i = i / 10;
    a[1] = i % 10;
    i = i / 10;
    a[2] = i % 10;
    i = i / 10;
    a[3] = i % 10;

    printf("%d %d %d %d", a[3], a[2], a[1], a[0]);
}
