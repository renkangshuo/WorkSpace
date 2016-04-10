#include "queue.h"
#include <stdio.h>

void enqueue( int x, int a[], int* head, int* tail, int size, int *total)
{

	if ( *total == size)
	{
		printf("Full\n");
		return ;
	}


	*total += 1;

	*tail += 1;
	*tail = *tail % size;
	int n = *tail;
	a[n] = x;
}

int dequeue(int a[], int *head, int* tail, int size, int *total)
{

	if( *tail == (*head - 1))
	{
		printf("empty\n");
		return -1;
	}

	*total -= 1;

	int n = *head;
	int value = a[n];
	*head += 1;
	*head %= size;

	return value;
}

void check(int a[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}
