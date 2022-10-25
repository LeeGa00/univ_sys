#include <stdio.h>

int sum(int a, int b) {
	int c;
	c = a + b;

	return(c);
}

int main(void) {
	int x = 10;
	int y ;
	y = sum(1, 2);

	printf("%d\n", x+y);
	return(0);
}
