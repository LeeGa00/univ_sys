// file : ex2-1.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("%s pid [id? | birthday? | QUIT | KILL]\n", argv[0]);
		exit(1);
	}

	pid_t pid = atoi(argv[1]);
	int status;

	if (strncmp(argv[2], "id?", strlen("id?")) == 0) {
		kill(pid, 10);
	}
	else if (strncmp(argv[2], "birthday?", strlen("birthday?")) == 0) {
		kill(pid, 12);
	}
	else if (strncmp(argv[2], "QUIT", strlen("QUIT")) == 0) {
		kill(pid, 3);
	}
	else if (strncmp(argv[2], "KILL", strlen("KILL")) == 0) {
		//kill(pid, 9); 
		kill(pid, SIGTERM); // kill parent and children
	}
	else {
		printf("%s pid [id? | birthday? | QUIT | KILL]\n", argv[0]);
	}
	return 0;
}
