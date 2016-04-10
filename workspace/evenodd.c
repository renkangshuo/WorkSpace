#include <stdio.h>

int main() {
	int num;
	int even_sum;
	int odd_sum;
	num = 0;
	even_sum = 0;
	odd_sum = 0;
	while(1) {
		printf("Input a number: \n");
		scanf("%d", &num);
		if (num == EOF)
			return 0;
		even_sum = 0;
		odd_sum = 0;
		for (int i = 0; i <= num; i++) {
			if (i % 2 == 0) 
				even_sum += i;
			else
				odd_sum += i;
		}
		printf("Even sum:%d \n", even_sum);
		printf("Odd sum:%d \n ", odd_sum);
	}
}



