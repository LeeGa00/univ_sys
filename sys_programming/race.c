#include <stdlib.h>
#include <unistd.h>
#include "ours.h"

void print_c (char *str) {
	char *ptr;
	int c;

	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}

int main(void) {
	pid_t pid;

	if((pid = fork()) < 0)
		perror("fork() error\n");
	else if (pid == 0)
		print_c("output from child\n");
	else
		print_c("output from parent\n");

	exit(EXIT_SUCCESS);
}
