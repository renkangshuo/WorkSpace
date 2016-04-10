#include "two_N.h"

struct node
{
	int ID;
	struct node* next;
};

struct local
{
	struct node* loc;
};

Local create_l(int total)
{
	Local position = malloc(sizeof( struct local ) );

	/* Initialization */

	position->loc = create_n();
	position->loc->ID = total;

	for (int i = total-1; i >= 1; i--) {
		Node temp = create_n();
		temp->ID = i;
		temp->next = position->loc->next;
		position->loc->next = temp;
	}


	position->loc = position->loc->next;
	
	return position;
}

Node create_n()
{
	Node temp = malloc(sizeof( struct node ) );
	temp->ID = 0;
	temp->next = temp ;

	return temp;
}

void check(Local location)
{
	Node temp;
	temp = location->loc;
	Node mark;
	mark = location->loc;

	do
	{
		printf("%d ", temp->ID);
		temp = temp->next;
	} while(temp != mark);
}

void check_one(Local location)
{
	printf("%d\n", location->loc->ID);
}

void delete_step(int step, Local location)
{
	Node temp = location->loc;
	
	while (location->loc->next != location->loc) {
		int n = step - 1;

		while (n--){
			location->loc = location->loc->next;
		}
		temp = location->loc->next;
		location->loc->next = temp->next;
		location->loc = temp->next;
		free(temp);
	}
}

