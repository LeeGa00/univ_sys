/* sleep-dump.c */
/* gcc -wall -g -o sleep-dump sleep-dump.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main(void) {
	sleep(60);

	exit(EXIT_SUCCESS);
}
