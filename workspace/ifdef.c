#include<stdio.h>
#define NUM 
int main() {
    struct stu{
        int num;
        char *name;
        float score;
    } *ps;

    ps = (struct stu*)malloc(sizeof(struct stu));
    ps->num = 102;
    ps->name = "David";
    ps->score = 92.5;

#ifdef NUM 
    printf("Number = %d\nScore = %f\n", ps->num, ps->score);
#else
    printf("Name=%s\n", ps->name);
#endif
    free(ps);

    return 0;
}
