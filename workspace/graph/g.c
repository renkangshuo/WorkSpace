#include <stdio.h>

int data[] = {'a', 'b', 'c', 'd'};

int s[4][4] = {
	{1,1,1,1},
	{1,1,1,1},
	{1,1,1,1},
	{1,1,1,1}
};

int get_first_neighbour(int s[][4], int v)
{
	int i;
	for (i = 0; i < 4; i++) {
		if (1 == s[v][i] && i != v)
			return i;
	}

	return -1;
}

int get_next_neighbour(int s[][4], int v, int u)
{
	int i;
	for (i = u + 1; i < 4;i++) {
		if (1 == s[v][i] && i != v)
			return i;
	}

	return -1;
}

int vistor[4] = {0};

void deep(int data[], int s[][4], int v)
{
	int u;
	if (1 == vistor[v])
		return;

	printf("%c ", data[v]);
	vistor[v] = 1;
	u = get_first_neighbour(s,v);
	while (-1 != u) {
		deep(data, s, u);

		u = get_next_neighbour(s, v, u);
	}

	return;
}

int ground(int data[], int s[][4], int v)
{
	int queue[10];
	int head = 0;
	int tail = 0;
	int vistor[4] = {0};
	int u;
	queue[tail++] = v;
	vistor[v] = 1;

	while (head != tail) {
		u = get_first_neighbour(s, queue[head]);
		while (-1 != u) {
			if (-1 != u && vistor[u] != 1)
				queue[tail++] = u;
			vistor[u] = 1;
			u = get_next_neighbour(s, queue[head], u);
		}
		printf("%c ", data[queue[head++]]);
	}

	printf("\n");
}

int main() 
{
	int v = 3;
	deep( data, s, v );

	printf("\n.................,,,,,,,,\n");

	ground( data, s , v );
	printf("\n.................,,,,,,,,\n");
}
