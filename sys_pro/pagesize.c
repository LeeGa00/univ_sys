/* pagesize.c */
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>

int main(void) {
	printf("page size: %ld btyes\n", sysconf(_SC_PAGESIZE));
	exit(EXIT_SUCCESS); 
}
