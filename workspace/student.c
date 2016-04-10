#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Student {
	char name[15];
	int  number;
	int  score;
} student;

void printArray(student *);
int compare(student *, student *);

typedef int (*comparefn)(const void *, const void *);

int main() 
{
	printf("Input: \n");
	printf("Name then number then score: \n");
	student s[N];

	for (int i=0; i < N; i++) {
		scanf("%s%d%d", s[i].name, &s[i].number, &s[i].score);
	}

	printf("Array before being sorted\n");
	printArray(s);
void printarray(void)
{
	int i;

	for (i = 0; i < 10; i++)

	qsort((void *) &s,
			N,
			sizeof(struct Student),
			(comparefn)compare);

	printf("\nList after sorting:\n");
	printArray(s);
}

void printArray(student *p) {
	for (int i=0; i < N; i++)
		printf("%s %d %d\n", p[i].name, p[i].number, p[i].score);
}

int compare (student *elem1, student *elem2) {
	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}
