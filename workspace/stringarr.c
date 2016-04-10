#include<stdio.h>

int main(int argc, const char *argv[])
{
    char s1[] = "Welcome";
    char s2[] = "to";
    char s3[] = "farsight";

    char* a1[3] = {s1, s2, s3};
    char* a2[3] = {"Welcome", "to", "farsight"};
    char **p;
    int i;
    return 0;
}
