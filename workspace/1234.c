#include<stdio.h>

int main() {
    int a[3];
    int count;
    count = 0;
    int n;
    n = 0;
    for (int i = 100; i < 1000; i++) {
            a[0] = i % 10;
            n = i / 10;
            a[1] = n % 10;
            a[2] = i / 100;
        
            if ( a[0] >= 1 && a[0] <= 4 && a[1] >= 1 && a[1] <= 4
                    && a[2] >= 1 && a[2] <= 4) {
                if (a[0] != a[1] && a[1] != a[2] && a[2] != a[0]) {
                    printf("%d%d%d\n", a[2], a[1], a[0]);
                    count++;
                }
            }
            printf("%d", count);
    }
}
