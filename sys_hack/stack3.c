/* stack3.c */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win(void) {
	printf("Done! Code flow changed\n");
}

int main(int argc, char **argv) {
	volatile int (*fp)();
	char buffer[64];

	fp = 0;

	gets(buffer);

	if(fp) {
		printf("Calling a function pointer, jumping to 0x%08x \n", fp);
		fp();
	}
	return(0);
}
