#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int array[10];
	int last;
} list_t;

list_t * list_create(void);
int list_insert(list_t *, int index, int x);
void list_print(list_t *);
int list_delete(list_t *, int index);
int list_locate(list_t *, int x);
void list_modify(list_t *, int index, int x);

int main() 
{
	list_t *p;
	p = list_create();

	for (int i=0; i < 5; i++)
		list_insert(p, 0, 88);

	
	list_modify(p, 2, 999);
	list_print(p);
	printf("88 is at %d\n", list_locate(p, 88));	
	return 0;
}

int list_delete(list_t *p, int index)
{
	if (index > p->last)
		return -1;
	int i;
    
	for (i = index; i <= p->last; i++)
		p->array[i] = p->array[i+1];

	p->last--;

	return 0;
}

list_t * list_create()
{
	list_t *p;
	p = (list_t *)malloc(sizeof(list_t));

	for (int i=0; i < (sizeof(p->array)/sizeof(int))-1; i++)
		p->array[i] = 0;
	p->last = -1;
	return p;

}

int list_insert(list_t *p, int index, int x) 
{
	if (index < 0 || index > p->last + 1)
		return -1;

	int i;
	for (i = p->last; i >= index; i--) {
		p->array[i+1] = p->array[i];
	}

	p->array[index] = x;
	p->last++;

	return 0;
}

void list_print(list_t *p) 
{
	for (int i=0; i < (sizeof(p->array)/sizeof(int))-1; i++)
		printf("%d ", p->array[i]);
	printf("\n");

	return;
}

int list_locate(list_t * p, int x)
{
	int i;
	int mark;
	
	for (i=0; i < (sizeof(p->array)/sizeof(int))-1; i++)
		if (p->array[i] == x)
		{
			mark = i;
			break;
		}

	return i;

}

void list_modify(list_t *p, int index, int x)
{
	p->array[index] = x;

	return;
}

