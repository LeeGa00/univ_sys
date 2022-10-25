#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win(void) {
	printf("Done!\n");
}

int main(int argc, char **argv) {
	volatile void (*fp)();
	char stuid[20];

	fp = 0;

	printf("Your student id: ");
	gets(stuid);

	if(fp)
		fp();
	else
		printf("Nothing happened!\n");
	
	return(0);
}
