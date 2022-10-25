/* abc1.c */
#include <stdio.h>

int a(int x, int y);
int b(int v);
int c(int v);

int main(void) {
	int x = 1;
	int y = 2;
	int z;

	z = a(x, y);

	printf("this is the func main(): %d\n", z);

	return(0);
}

int a(int x, int y) {
	int v1, v2;
	printf("this is the func a\n");
	v1 - b(x);
	v2 = c(y);
	return(v1 + v2);
}

int b(int v) {
	printf("this is the func v: %d\n", v);
	return(v);
}

int c(int v) {
	printf("this is the func c: %d\n", v);
	return(v);
}
