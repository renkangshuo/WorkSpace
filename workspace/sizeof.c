#include <stdio.h>

struct S3 {
    char c;
    int i[2];
    double v;
}s;

union U3 {
    char c;
    int i[2];
    double v;
}u;
int main () {

    
    printf("%d\n", sizeof(s));
    printf("%d\n", sizeof(u));
    return 0;
}
