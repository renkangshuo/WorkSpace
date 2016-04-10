#include<stdio.h>
#define N 10
typedef struct {
    int name;
    int number;
    int flag;
} people;
int main(int argc, const char *argv[])
{
	people p = {1, 2, 3};
	people temp;
	temp = p;
	printf("%d %d %d\n", p.name, p.number, p.flag);
	printf("%d %d %d\n", temp.name, temp.number, temp.flag);
}

