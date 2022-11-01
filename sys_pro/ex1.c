// file : ex1.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define ID "20011694"
#define BIRTHDAY "010512"

void funcID() {
	int status;
	pid_t pid = fork();

	if (pid < 0) {
		printf("fork error\n");
	}
	else if (pid == 0) {
		printf("responding process(%d), id: %s\n", getpid(), ID);
		exit(0);
	}
	else {
		wait(&status);
		printf("calling process(%d)\n", getpid());
	}
}

void funcBIRTHDAY() {
	int status;
	pid_t pid = fork();

	if (pid < 0) {
		printf("fork error\n");
	}
	else if (pid == 0) {
		printf("responding process(%d), birthday: %s\n", getpid(), BIRTHDAY);
		exit(0);
	}
	else {
		wait(&status);
		printf("calling process(%d)\n", getpid());
	}
}

int main(int argc, char *argv[]) {
	pid_t pid;
	int status;

	if(argc != 2) {
		printf("%s [id? | birthday?]\n", argv[0]);
		exit(1);
	}

	else if (strncmp(argv[1], "id?", strlen("id?")) == 0) {
		funcID();
	}
	else if (strncmp(argv[1], "birthday?", strlen("birthday?")) == 0) {
		funcBIRTHDAY();
	}
	else {
		printf("%s [id? | birthday?]\n", argv[0]);
	}

	return(0);
}
