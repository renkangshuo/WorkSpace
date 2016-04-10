#include <stdio.h>

int i = 5;
int main() {
    int  i;

    if (i != 5)
        printf("it is local\n");
    printf("i is %d\n", i);

    return 0;
}
