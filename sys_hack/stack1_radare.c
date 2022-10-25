/* stack1_radare.c */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

int main(int argc, char **argv) {
	volatile int modified;
	char buffer[64];

	if(argc == 1)
		errx(1, "please specify an argument\n");

	modified = 0;
	strcpy(buffer, argv[1]);

	if(modified == 0x61626364)
		printf("Done!\n");
	else
		printf("Try again\n");

	return(0);
}
