#include "queue.h"

struct queue {
	int data;
	Q next;
};

struct h_t {
	Q head;
	Q tail;
};

HT create_ht()
{
	HT ht = malloc(sizeof (struct h_t));
	ht->head = create();
	ht->tail = ht->head;

	return ht;
}

Q create()
{
	Q q = malloc( sizeof (struct queue) );
	q->next = NULL;

	return q;
}

void join(int x, HT ht)
{
	Q temp = malloc(sizeof (struct queue) );
	temp->data = x;
	temp->next = ht->tail->next;
	ht->tail->next = temp;
	ht->tail = temp;
}

int gone(HT ht)
{
	if (ht->head->next == NULL)
	{
		printf("Zero\n");
		return -1 ;
	}
	else if (ht->head->next == ht->tail)
	{
		Q temp = ht->tail;
		ht->head->next = NULL;
		ht->tail = ht->head;
		free(temp);
		printf("One\n");
		
		return 0;
	}
	else {
	Q temp = ht->head->next;
	ht->head->next = temp->next;
	free(temp);

	return 0;
	}
	return 0;


}

void check( HT ht)
{
	Q temp = ht->head->next;

	while (temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n<><><<<<><><><><><<<<\n");
}
