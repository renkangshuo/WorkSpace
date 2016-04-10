#include "stack.h"
/* stack implementation is a linked list with a header */

struct node 
{
	int data;
	ptr_node next;	
};

void check( stack s )
{
	stack temp;
	temp = s->next;

	while (temp) {
		printf("%d >", temp->data);
		temp = temp->next;
	}
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>\n");
}

int is_empty( stack s)
{
	return s->next == NULL;
}

stack create_stack( void )
{
	stack s;

	s = malloc( sizeof (struct node) );
	if ( s == NULL)
		printf("out of space!\n");
	s->next = NULL;
	make_empty( s );
	return s;
}

void make_empty( stack s )
{
	if ( s == NULL )
		printf("Must create stack first\n");
	else
		while( !is_empty( s ))
			pop(s);
}

void push (int x, stack s )
{
	ptr_node temp;

	temp = malloc( sizeof( struct node) );
	if (temp == NULL)
		printf("Out of space!\n");
	else{
		temp->data = x;
		temp->next = s->next;
		s->next = temp;
	}
}

int top( stack s )
{
	if (!is_empty( s ) )
		return s->next->data;
	printf("Empty stack\n");
	return 0;  /* Return value used to avoid warining */
}

void pop( stack s )
{
	ptr_node first;

	if (is_empty( s ) )
		printf("Empty stack\n");
	else{
		first = s->next;
		s->next = s->next->next;
		free(first);
	}
}


