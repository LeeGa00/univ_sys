// file : ex2-2.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define ID "20011694"
#define BIRTHDAY "010512"

pid_t pid_i, pid_b;


void signalHandlerQUIT() {
	printf("responding process(%d), No, QUIT\n", getpid());
}

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
		waitpid(pid, &status, 0);
	}
}

void funcBIRTHDAY() {
	int status;
	int p[2];
	int buf[30];

	if (pipe(p) < 0)
		perror("pipe error");

	if (pid_b == 1){
		pid_b = fork();
	}

	if (pid_b < 0) {
		printf("fork error\n");
		
	}
	else if (pid_b == 0) {
		 write(p[1], "my birthday : 12.17", 19);
		 printf("responding process(%d), birthday: %s\n", getpid(), BIRTHDAY);
		 exit(0);
	}
	else {
		read(p[0], buf, 19);
		waitpid(pid_b, &status, 0);
	}
}

int main(void) {
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	pid_i = pid_b = 1;

	act.sa_handler = funcID;
	sigaction(10, &act, NULL);

	act.sa_handler = funcBIRTHDAY;
	sigaction(12, &act, NULL);

	act.sa_handler = signalHandlerQUIT;
	sigaction(3, &act, NULL);

	printf("my pid: %d\n", getpid());

	while(1) {
		sleep(1);
	}	
	return 0;
}
