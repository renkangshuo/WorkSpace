#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head;

struct Node* create_node(int x) 
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = x;
	new_node->prev = NULL;
	new_node->next = NULL;
}

int insert_head(int x)
{
	struct Node* new_node = create_node(x);

	if (head == NULL) {
		head = new_node;
		return 0;
	}

	head->prev = new_node;
	new_node->next = head;
	head = new_node;

	return 0;
}

int insert_tail(int x)
{
	struct Node* new_node = create_node(x);
	struct Node* temp;
	if (head == NULL) {
		head = new_node;
		return  0;
	}

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
}

void print() 
{
	if (head == NULL)
		return;

	struct Node* temp;

	temp = head;
	while (temp != NULL) {
		printf("%d > ", temp->data);
		temp = temp->next;
	}
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	return;
}

void print_reverse()
{
	if (head == NULL)
		return;
	struct Node* temp;

	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	while (temp != NULL) {
		printf("%d > ", temp->data);
		temp = temp->prev;
	}
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	return;
}

struct Node* find(int x) 
{
	struct Node* temp;
	temp = head;

	while (temp != NULL && temp->data != x) {
		temp = temp->next;
	}

	return temp;
}

int delete_list() 
{
	struct Node* temp;
	temp = head;
	struct Node* t;

	while (temp != NULL) {
		t = temp->next;
		free(temp);
		temp = t;
	}

	return 0;
}
int delete_one(int x) 
{
	struct Node* temp = find(x);
	
	if (temp->prev == NULL) {
		head = temp->next;
		free(temp);
	}
	else if (temp->next == NULL) {
		temp->prev->next = NULL;
		free(temp);
	}
	else{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}

	return 0;
}
int main() 
{
	head = NULL;

	insert_head(99);
	insert_head(88);
	insert_tail(234);
	insert_tail(345);
	for (int i=9; i > 0; i--)
		insert_head(i);

	for (int i=89; i>79; i--)
		insert_tail(i);

	print();
	printf("\nDelete<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>\n");
	delete_one(345);
	delete_one(234);
	print();
	printf("\n delete first end <<<<<<<<<<<<<<<<>>>>>>>>>>>\n");
	delete_one(1);
	delete_one(80);
	print();
}
