#include "queue.h"
#define N 8

int total = 0;

int main()
{
	int a[N];
	int head;
	int tail;
	 head = 1;
	 tail = 0;

	for (int i= 0; i < N; i++)
		a[i] = 0;

	enqueue( 10, a, &head, &tail, N, &total);
	check( a, N);
	enqueue( 18, a, &head, &tail, N, &total);
	check( a, N);
	dequeue(a, &head, &tail, N, &total);
	check( a, N);
	
	
}
