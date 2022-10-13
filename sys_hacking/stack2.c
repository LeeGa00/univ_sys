#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <err.h>

int main(int argc, char **argv) {
	volatile int modified;
	char buffer[64];
	char *variable;

	variable = getenv("GREENIE");

	if(variable == NULL) {
		errx(1, "plx, set the GREENIE environment variable!\n");
	}

	modified = 0;
	strcpy(buffer, variable);

	if(modified == 0x0d0a0d0a) {
		printf("Done! You have correctly modified the variable!\n");
	}
	else {
		printf("Try again, you got 0x%08x\n", modified);
	}
	return(0);
}
