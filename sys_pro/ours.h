/* ours.h */

#include <stdio.h>
#include <sys/wait.h>

void print_exit(int status) {
	if (WIFEXITED(status))
		printf("normal, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFEXITED(status))
		printf("abnormal, signal number = %d\n", WTERMSIG(status));
}
