#include<stdio.h>

int main() {
    printf("The file is %s\n", __FILE__);

    printf("The line is %d\n", __LINE__);
    printf("The function is %s\n", __FUNCTION__);
    printf("The data is %s\n", __DATE__);
    printf("The time is %s\n", __TIME__);

    return 0;
    }
