/* print-env.c */
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[]) {

	int i;
	char **ptr;

	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);

	/* print argv */
	for (ptr = environ; *ptr != NULL; ptr++)
		printf("%s\n", *ptr);

	exit(EXIT_SUCCESS);
}
