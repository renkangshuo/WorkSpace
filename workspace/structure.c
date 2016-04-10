#include <stdio.h>
struct S1 {
    int i;
        char c;
        int j;
};

int main() {
    struct S1 s;
    s.i = 1;
    s.c = 'a';
    s.j = 1;

    struct S1* ps;
    ps = &s;
    printf("%d\n", ps->i);
}

