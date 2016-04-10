#include "stacka.h"

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct stack_record
{
	int capacity;
	int top_stack;
	int* array;
};

int is_full( stack s )
{
	return s->top_stack == s->capacity - 1;
}

stack create_stack( int max_elements)
{
	stack s;

	if( max_elements < MinStackSize)
		printf("Stack size is too small\n");

	s = malloc( sizeof( struct stack_record) );
	if (s == NULL)
		printf("Out of space \n");

	s->array = malloc( sizeof( int ) * max_elements);
	if (s->array == NULL)
		printf("Out of space\n");
	s->capacity = max_elements;
	make_empty( s );

	return s;
}

void dispose_stack( stack s )
{
	if (s != NULL)
	{
		free( s->array );
		free( s );
	}
}

int is_empty( stack s )
{
	return s->top_stack == EmptyTOS;
}



void make_empty( stack s )
{
	s->top_stack = EmptyTOS;
}

void push( int x, stack s )
{
	if (is_full( s ) )
		printf("Full stack\n");

	s->array[++s->top_stack] = x;
}

int top( stack s )
{
	if ( !is_empty( s ))
		return s->array[ s->top_stack];
	printf("Empty stack\n");
	return 0;
}

void pop( stack s )
{
	if (is_empty( s ) )
		printf("empty stack\n");
	else
		s->top_stack--;
}

int top_pop( stack s )
{
	if (is_empty( s ) )
		printf("empty stack\n");
	else
		return s->array[s->top_stack--];
}
