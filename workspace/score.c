#include <stdio.h>

int main() {
    int score = 0;
    printf("Put your score\n");
    scanf("%d", &score);
    if (score <= 100 && score > 90)
        printf("You good student\n");
    else if ( score > 80)
        printf("You not good student\n");
    else if ( score > 70) 
        printf(" idiot\n");
    else if ( score > 60)
        printf(" idiot1\n");
    else 
        printf(" no pass");
}
