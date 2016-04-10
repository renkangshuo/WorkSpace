#include "circle.h"

struct circle 
{
	int data;
	C next;
};

struct position
{
	C tail;
};

P create_p(void)
{
	P pos = malloc(sizeof (struct position));
	pos->tail = create();
	pos->tail->next = pos->tail;

	return pos;
}

C create(void)
{
	C cir = malloc(sizeof (struct circle) );
	cir->next = NULL;

	return cir;
}

void join( int x, P p )
{
	C temp  = malloc( sizeof (struct circle ) );
	temp->data = x;
	temp->next = p->tail->next;
	p->tail->next = temp;
	p->tail = temp;
	
}

int gone( P p )
{
	if (p->tail == NULL)
		return -1;
	else if ( p->tail->next->next == p->tail)
	{
		C temp;
		temp = p->tail;
		p->tail = p->tail->next;
		free(temp);
		return 0;
	}
	else {
	C temp;
	temp = p->tail->next->next;
	p->tail->next->next = temp->next;
	free (temp);
	return 0;
	}
}

void check( P p)
{
	if (p->tail == p->tail->next)
		return;
	C temp = p->tail->next;
	do
	{
		temp = temp->next;
		printf("%d ", temp->data);
	}while (temp != p->tail->next);
	printf("\n");

	return ;

}
