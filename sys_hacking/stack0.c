/* stacj0.c */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	volatile int modified;
	char buffer[64];

	modified = 0;

	gets(buffer);

	if(modified != 0)
		printf("Done!\n");
	else
		printf("Try again\n");

	return(0);
}
