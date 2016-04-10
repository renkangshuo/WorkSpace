#include<stdio.h>

int a[3] = {1, 3, 5};
int fact(int n) {
	int result = 1;
	while (n > 1) {
		result *= n;
		n--;
	}
	return result;
}
int main() {
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += fact(a[i]);
	}

	printf("%d\n", sum);
	return 0;
}


