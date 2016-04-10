#include <stdio.h>

int a[][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
    int year;
    int month;
    int day_of_month;
    int four;
    int day_of_year;
    four = 0;
    day_of_year = 0;
    year = 0;
    month = 0;
    day_of_month = 0;

    printf("Please input year: \n");
    scanf("%d", &year);
    printf("input month: \n");
    scanf("%d", &month);
    printf("input day_of_month: \n");
    scanf("%d", &day_of_month);
    if ((year % 4 == 0 && year % 100 !=0) || year % 400 == 0)
        four = 1;
    for(int i = 1; i < month; i++)
        day_of_year += a[four][i];
    day_of_year += day_of_month;

    printf("Day of the year: \n");
    printf("%d\n", day_of_year);
}
    
