#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "ours.h"

char buf[] = "wrtie to stout\n";

int main(void) {
	pid_t pid;

	if (write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf))
		perror("write error\n");

	printf("printf by %d: before fork\n", getpid());

	if((pid = fork()) < 0)
		perror("fork error\n");
	else if(pid == 0)
		printf("printf by %d: hi from child!\n", getpid());
	else /* parent */
		printf("printf by %d: hi from parent\n", getpid());

	printf("printf by %d: bye\n", getpid());

	exit(EXIT_SUCCESS);
}
