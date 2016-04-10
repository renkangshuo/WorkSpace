#include<stdio.h>
int complete(int );
int main() {
	for (int i = 1; i <= 100000; i++)
		if ( complete(i) > 0) 
			printf("%d\n", complete(i));
	
		
}

int complete(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		return sum;
	else
		return -1;
}
		
