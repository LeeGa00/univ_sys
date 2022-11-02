/* mmap-ipc.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(void) {
	int *addr;

	addr = mmap(NULL, sizeof(int), 
			PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANONYMOUS, 
			-1, 0);

	if(addr == MAP_FAILED) {
		perror("mmap() error");
		exit(1);
	}

	// we insert the value of 42 in memory
	*addr = 42;

	switch (fork()) {
		case -1:
			perror("fork() error");
			break;

		/* child part */
		case 0:

			// child gets (prints) the value in memory
			printf("child: %d\n", *addr); 

			// child increases the value in memory
			(*addr)++;
			break;

		/* parent part */
		default:

			// parent waits to die its chlid
			if(wait(NULL) == -1) {
				perror("wait() error");
				exit(1);
			}

			// parent gets (prints) the value in memory
			printf("parent: %d\n", *addr);
	}

	exit(EXIT_SUCCESS);
}
