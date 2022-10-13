/* pipe1.c */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void main(void) {
	int pfd[2]; // pipe descriptors
	char buf[30];

	/* here, we create two pipes */
	if(pipe(pfd) == -1) {
		perror("pipe error");
		exit(1);
	}

	/* pfd[1] is for writing */
	printf("Writing to the file descriptor 3%d\n", pfd[1]);
	write(pfd[1], "pipe!", 5);

	/* pfd[0] is for reading */
	printf("Reading from the file descriptor 3%d\n", pfd[0]);
	read(pfd[0], buf, 5);

	printf("%s\n", buf);

}
