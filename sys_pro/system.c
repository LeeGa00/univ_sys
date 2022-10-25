#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include "ours.h"

// ehre, we use several commands such as grep, cut, and pipeline
char *cmd = "grep hurryon /etc/passwd | cut -f 5 -d:";

int main(void) {
	int status;
	if((status = system(cmd)) == -1)
		perror("system() error");

	print_exit(status);

	exit(EXIT_SUCCESS);
}
