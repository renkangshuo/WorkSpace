#include <stdio.h>

int main() {
	int x = 10;
	int y = 100;

	x = x + y;
	y = x - y;
	x = x - y;

	printf("%d %d\n", x, y);
}
