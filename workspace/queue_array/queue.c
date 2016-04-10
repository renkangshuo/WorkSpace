#include "queue.h"

struct QueueRecord
{
	int capacity;
	int front;
	int rear;
	int size;
	int *array;
};

void check( Queue Q )
{
	int n = Q->capacity;
	
	while ( n-- )
		printf("%d ", Q->array[n]);
	printf("\n");

	return;
}

int is_empty( Queue Q )
{
	return Q->size == 0;
}

void make_empty( Queue Q )
{
	Q->size = 0;
	Q->front = 1;
	Q->rear = 0;

	return;

}

static int succ( int value, Queue Q )
{
	if (++value == Q->capacity )
		value = 0;
	return value;
}

void enqueue(int x, Queue Q )
{
	if (is_full( Q ) )
	{
		printf("Full\n");
		return;
	}
	else
	{
		Q->size++;
		Q->rear = succ( Q->rear, Q );
		Q->array[ Q->rear ] = x;

		return;
	}
}

int front( Queue Q )
{
	return Q->array[ Q->front ];
}

void dequeue( Queue Q )
{
	if ( Q->size == 0 ) {
		printf("Empty\n");
		return;
	}

	Q->front = succ( Q->front, Q );

	return;
}

int front_dequeue( Queue Q )
{
	if ( Q->size == 0 ) {
		printf("Empty\n");
		return -1;
	}

	int temp = Q->array[ Q->front ];
	Q->front = succ( Q->front, Q );
	return temp;
}

int is_full( Queue Q )
{
	return Q->size == Q->capacity;
}

Queue create(int maxelements)
{
	Queue temp;
	temp = malloc(sizeof(struct QueueRecord ));

	temp->capacity = maxelements;
	temp->size = 0;
	temp->array = calloc(maxelements ,sizeof( int ) * maxelements);
	temp->front = 1;
	temp->rear = 0;

	return temp;
}
