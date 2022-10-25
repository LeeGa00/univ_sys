#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ours.h"

int main(void) {
	pid_t pid;
	int status;

	if((pid = fork()) < 0)
		printf("fork error");
	else if (pid == 0) exit(7);

	if (wait(&status) != pid) perror("wait error");

	print_exit(status);

	if ((pid = fork()) <0)
		perror("fork error");
	else if (pid == 0)
		abort();

	if (wait(&status) != pid) perror("wait error");
	
	print_exit(status);

	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0)
		status /= 0;

	if (wait(&status) != pid) perror("wait error");

	print_exit(status);

	exit(EXIT_SUCCESS);
