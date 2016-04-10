#include<stdio.h>

int main(int argc, const char *argv[])
{
    int a[10];
    char *p = "Hello,World";

    char *pa;
    pa = (char *)&a;
    while (*p) {
        *pa = *p;
        pa++;
        p++;
    }
    *pa = '\0';
    printf("%s\n", (char *)a);
    printf("a= %p\n", a);
    printf("a+1= %p\n", a+1);
    printf("&a[0]= %p\n", &a[0]);
    printf("&a[0]+1= %p\n", &a[0]+1);
    printf("&a = %p\n", &a);
    printf("&a+1 =%p\n", &a+1);
    return 0;
}
