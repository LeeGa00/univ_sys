/* execve1.c */
/* gcc -o execve1 execve1.c */

#include <unistd.h>
#include <stdio.h>

int main(void) {
	char *arg1 = "-al";
	char *arg2 = "/etc";
	char *command_name = "ls";
	char *argv[] = {command_name, arg1, arg2, NULL};
	char *command_full_path = "/bin/ls";

	execve(command_full_path, argv, NULL);

	return 0;
}
