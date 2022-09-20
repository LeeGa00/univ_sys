#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ours.h"

int main(void) {
	pid_t pid;
	int i;

	for(i = 0; i<5; i++) {
		if((pid = fork()) < 0){
			perror("fork error\n");
		} else if (pid == 0){
			printf("child %d: %d\n", i, getpid());
			exit(EXIT_SUCCESS);
		}
		/* parent does nothing */
	}

	/* during this time, let's check out the zombies */
	/* ps -ef */
	sleep(30);

	printf("bye from parent\n");

	exit(EXIT_SUCCESS);
}
