#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef int data_t;
typedef struct {
	data_t *data;
	int last;
	int number;
}list_t;

list_t *creat_list(int number)
{
	list_t *p;
	p = malloc(sizeof(list_t));
	p->data = malloc(number * sizeof(data_t)); //DATA[N]
	p->number = number; //N
	p->last = -1;

	return p;
}

/*
 * insert element
 */
int ins_list(list_t *p, int index, const data_t * data)
{
	int i;

	if (( p->number - 1) == p->last)
		return -1;

	if (0 > index || index > p->last + 1)
		return -2;

	for (i = p->last; i >= index; i--) {
		p->data[i+1] = p->data[i];
	}

	p->data[index] = *data;
	p->last++;

	return 0;
}

int del_list(list_t *p, int index)
{
	
	int i;

	if(-1 == p->last)
		return -1;
	if(0 > index || index > p->last)
		return -2;

	for(i = index + 1;i <= p->last;i++) {
		p->data[i-1] = p->data[i];
	}

	p->last--;

	return 0;
}

int locate_list(list_t *p, const data_t *data)
{
	int i;

	for (i = 0; i <= p->last; i++) {
		if (*data == p->data[i])
			return i;
	}
	return -1;
}

int change_index(list_t *p, int index, const data_t *newdata)
{
	if (-1 == p->last)
		return -1;
	if (0 > index || index > p->last)
		return -2;

	p->data[index] = *newdata;

	return 0;
}

int clean_list(list_t *p)
{
	p->last = -1;
	return 0;
}

int isEmpty(list_t *p)
{
	return -1 == p->last;
}

int isFull(list_t *p)
{
	return p->number - 1 == p->last;
}

int clear(list_t * *pp)
{
	free((*pp)->data);
	free(*pp);
	*pp = NULL;
	return 0;
}

void print_list(list_t *P)
{
	int i;

	for (i = 0; i <= p->last; i++) {
		printf("last = %d\n", p->last);
	}

	printf("\n");
	printf("last = %d\n", p->last);

	return;
}

int main(int argc, const char *argv[])
{
	list_t *p;
	list_t *p1;

	int i;
	data_t buf;
	p = creat_list(12);
	p1 = creat_list(100);

	for (i = 9; i >= 0; i--) {
		ins_list(p, 0, &i);
	}

	buf = 234;
	ins_list(p, 3 , &buf);

	print_list(p);

	del_list(p, 5);
	print_list(p);

	return;
}
