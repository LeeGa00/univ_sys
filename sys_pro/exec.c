#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	printf("executing ls\n");

	execl("/bin/ls", "ls", "-1", (char *)0);

	// the following code is only executed when execl() fails
	// because the /bin/ls will replace the code
	perror("execl() failed\n");

	return(0);
}
