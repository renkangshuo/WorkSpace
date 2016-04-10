#include "double.h"

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct ht {
	struct node* head;
	struct node* tail;
};

struct node* create_n()
{
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

struct ht* create_ht()
{
	struct ht* temp = malloc(sizeof(struct ht));
	temp->head = create_n();
	temp->tail = create_n();

	temp->head->next = temp->tail;
	temp->tail->prev = temp->head;

	return temp;
}

void insert_at_head(int x, struct ht* htp)
{
	struct node* temp = create_n();

	temp->data = x;

	temp->next = htp->head->next;
	temp->prev = htp->head;
	htp->head->next->prev = temp;
	htp->head->next = temp;

	return;
}

void insert_at_tail(int x, struct ht* htp)
{
	struct node* temp = create_n();

	temp->data = x;

	temp->prev = htp->tail->prev;
	temp->next = htp->tail;
	htp->tail->prev->next = temp;
	htp->tail->prev = temp;

	return;
}

void delete_at_head(struct ht* htp)
{
	struct node* temp = htp->head->next;

	htp->head->next = temp->next;
	temp->next->prev = temp->prev;

	free(temp);

	return;
}

void delete_at_tail(struct ht* htp)
{
	struct node* temp = htp->tail->prev;

	htp->tail->prev = temp->prev;
	temp->prev->next = temp->next;

	free(temp);

	return;
}

void check_from_head(struct ht* htp)
{
	struct node* temp = htp->head->next;

	while (temp != htp->tail) {
		printf("%d  ", temp->data);
		temp = temp->next;
	}

	printf("\n,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
}

void check_from_tail(struct ht* htp)
{
	struct node* temp = htp->tail->prev;

	while (temp != htp->head) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}

	printf("\n..............................\n");
}






