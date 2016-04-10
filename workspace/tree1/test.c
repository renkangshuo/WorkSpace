#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

typedef struct node {
	data_t data;
	struct node* left;
	struct node* right;
} tree;

tree* init_root(int num)
{
	tree* root;
	if(num > 6)
		return NULL;

	root =malloc(sizeof(tree));
	printf("%d\n", num);

	root->data = num;
	root->left = init_root(2 * num);
	root->right = init_root(2 * num + 1);
	return root;
}

void print(tree* t)
{
	if (t == NULL)
		return;
	print(t->left);
	print(t->right);
	printf("  %d \n", t->data);
}


void leve_tree(tree* t)
{
	tree* queue[20];
	int head = 0;
	int tail = 0;

	tree* node;

	queue[tail++] = t;
	while (head != tail)
	{
		if(queue[head]->left != NULL)
			queue[tail++] = queue[head]->left;
		if(queue[head]->right != NULL)
			queue[tail++] = queue[head]->right;
		node = queue[head++];

		printf("%d ", node->data);
	}

	printf("\n");
	
}

int stack_pre(tree* root)
{
	tree **stack;
	stack = malloc(sizeof(tree *) * 100);

	int top = -1;
	printf("stack_pre:");
	while(-1 != top || NULL != root) {
		
		while(NULL != root) {
			stack[++top] = root;
			root = root->left;
		}
		root = stack[top--];
		printf("%d ", root->data); //middle
		root = root->right;
	}
}

int stack_post(tree* root)
{
	struct ss {
		tree* root;
		int flag;
	}*stack;
	int top = -1;
	stack = malloc(sizeof(struct ss) * 100);

	printf("stack post:");
	while(NULL != root || -1 != top) {
		while(NULL != root) {
			stack[++top].root = root;
			stack[top].flag = 1;
			root = root->left;
		}

		if (1 == stack[top].flag) {
			root == stack[top].root->right;
			stack[top].flag = 2;
			continue;
		}
		if (2 == stack[top].flag) {
			printf("%d ", stack[top--].root->data);
			continue;
		}
	}

	printf("\n");
}
int main(int argc, const char *argv[])
{
	tree *root;
	root = init_root(1);

	
	return 0;
}
