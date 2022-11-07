/* execve2.c */

#include <unistd.h>
#include <stdio.h>

int main(void) {
	char *command_name = "sh";
	char *argv[] = {command_name, NULL};
	char *command_full_path = "/usr/bin/sh";

	execve(command_full_path, argv, NULL);
	
	return 0;

}
