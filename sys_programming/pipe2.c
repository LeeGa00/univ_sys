/* pipe2.c */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void) {
	int pfd[2]; // pipe descriptors
	char buf[30];

	/* here, we create two pipes */
	if(pipe(pfd) == -1) {
		perror("pipe error");
		exit(1);
	}

	if(!fork()) {
		printf("CHILD(PID: %d): Writing to the pipe\n", getpid());

		/* wrtiing data into the pipe */
		write(pfd[1], "pipe!", 5);

		/* exiting of a child process */
		exit(0);
	}
	else {
		printf("PARENT(PID: %d): Reading from the pipe\n". getpid());

		/* reading data from the pipe */
		read(pfd[0], buf, 5);
		printf("PARENT(PID: %d): %s\n", getpid(), buf);

		/* waiting for the child process */
		wait(NULL);
	}

	return 0;
}

