#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int data;
	struct listnode *next;
} list_node;

list_node * create_link() {
	list_node* p = (list_node*)malloc(sizeof(list_node));
	p->next = NULL;

	return p;
}

int insert_at_random(list_node* random, int x) {
	list_node*p = malloc(sizeof(list_node));
	p->data = x;

	p->next = random->next;
	random->next = p;

	return 0;

	
}
int insert_at_head(list_node* head, int x) {
	list_node *p = (list_node*)malloc(sizeof(list_node));
	/* data initialization */
	p->data = x;
	/* insert operation */
	p->next = head->next;
	head->next = p;

	return 0;
}

void print_list(list_node *head) {
	list_node *p;
	p = head->next;

	while (p != NULL) {
		printf("%d >> ", p->data);
		p = p->next;
	}
	return ;
}

void print_list1(list_node *head) {
	while (head) {
		printf("%d >> ", head->data);
		head = head->next;
	}
	return;
}
int is_empty( list_node* head)
{
	return head->next == NULL;
}

list_node* find( list_node* head, int x)
{
	list_node* p = head->next;

	while (p != NULL && p->data != x)
		p = p->next;
	
	return p;
}

list_node* findprev( list_node *head, int x)
{
	list_node* p = head;

	while(p != NULL && p->next->data != x)
		p = p->next;

	return p;
}

int is_last(list_node* p)
{
	return p->next == NULL;
}

void delete_one(list_node* head, int x)
{
	list_node* p;
	list_node* temp;

	p = findprev(head, x);

	if (p == NULL)
		return;

	if ( !is_last(p)) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	return;
}

void delete_list(list_node* head)
{
	list_node* p;
	list_node* temp;

	p = head->next;
	head->next = NULL; /* Initial state */

	while (p != NULL)
	{
		temp = p->next;
		free (p);
		p = temp;
	}
}

void insert_number(list_node* head, int n, int x)
{
	list_node* p;
	list_node* temp;

	p = head->next;

	while (n-- && p != NULL) {
		p = p->next;
	}

	if (n != -1)
		return;

	temp = malloc(sizeof(list_node));
	temp->data = x;
	temp->next = p->next;
	p->next = temp;

	return;


}

list_node* reverse(list_node* head)
{
	list_node* newhead = 0;

	while ( head ) {
		list_node* next = head->next;
		head->next = newhead;
		newhead = head;
		head = next;
	}
	return newhead;
}

int main() 
{
	list_node *head;
	list_node* newhead;

	head = create_link();
	

	for (int i=10; i>=0; i--)
		insert_at_head(head, i);

	print_list(head);
	printf("NULL");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
/*
	delete_one(head, 88);
	delete_one(head, 99);

	print_list(head);
	printf("NULL");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
*/
	/*insert_at_random( find(head, 5), 77);
	insert_at_random( find(head, 6), 77);
	insert_at_random( find(head, 7), 77);

	print_list(head);
	printf("NULL");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	insert_number(head, 56, 999);
	insert_number(head, 3, 888);
	insert_number(head, 6, 777777777);

	print_list(head);
	printf("NULL");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
*/
	newhead = reverse(head->next);
	print_list1(newhead);
	printf("NULL");
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
