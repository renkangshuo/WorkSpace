#include<stdio.h>
#define N 10

typedef struct element {
    int name;
    int number;
    int flag ;
} people; 


people p[N];
int main(int argc, const char *argv[])
{
    int i, j, k;
    int count = 0;
    int count1 = 0;
    int last;
    int zero = 0;
    i = 0;
    j = 0;
    k = 0;
    for (i = 0; i < N; i++) {
        p[i].name = i + 1;
        p[i].flag = 1;
        p[i].number = ((i) % 3) + 1;
    }
    last = p[i-1].number;


    while (count != 1) {
        zero = 0;
        count1 = 0;
/*    for (j = 0; j < N; j++) {
        if (p[j].flag == 1)
            last = p[j].number;
    }*/
    for (k = 0; k < N; k++){
        if (p[k].number % 3 == 0 && p[k].flag ==1)
        {
            p[k].flag = 0;
        }
    }

    for (i = 0; i < N; i++){
        if (p[i].flag == 1){
            count1++;
        }
    }

    count = count1;

    for (i = 0; i < N; i++){
        if (p[i].flag == 1)
        p[i].number = (last + zero++) % 3 + 1;
    }
    last = p[i-1].number;
    }
    for (i = 0; i < N; i++)
        if (p[i].flag == 1)
            printf("%d\n", p[i].name);
    
    return 0;
}
