// file : ex2-2.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define ID "20011699"
#define BIRTHDAY "2001.12.17"

pid_t pid_i, pid_b;

void signalHandler(int sig) {
	if (sig == SIGQUIT)
		printf("responding process(%d), No, QUIT\n", getpid());
	else if (sig == SIGTERM) {
		// kill parent and children!
		if (pid_i != 2)
			kill(pid_i, 9);
		if (pid_b != 2)
			kill(pid_b, 9);
		kill(getpid(), 9);
	}
}

void funcID() {
        int p[2];
        char buf[30] = {'\0'};

        if (pid_i == 2){
		if(pipe(p) < 0)
                	perror("pipe error");
		pid_i = fork();
	}

	if (pid_i < 0) {
		printf("fork error\n");
	}
	else if (pid_i == 0) {
		while(1) {
                        read(p[0], buf, 10);
                        printf("responding process(%d) / %s\n", getpid(), buf);
                }
	}
	else {
		//printf("parent process(%d)\n", getpid());
                write(p[1], ID, 10);
	}
}

void funcBIRTHDAY() {
	int status;
	int p[2];
	char buf[30] = {'\0'};

	if (pid_b == 2 && pipe(p) < 0)
		perror("pipe error");

	if (pid_b == 2){
		pid_b = fork();
	}

	if (pid_b < 0) {
		printf("fork error\n");
		
	}
	else if (pid_b == 0) {	
		while(1) {
			read(p[0], buf, 19);
			printf("responding process(%d) / %s\n", getpid(), buf);
		}
	}
	else {
                //printf("parent process(%d)\n", getpid());
		write(p[1], "my birthday : 12.17", 19);
	}
}

int main(void) {
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	int p_I[2], p_B[2];


	pid_i = pid_b = 2;

	act.sa_handler = funcID;
	sigaction(10, &act, NULL);

	act.sa_handler = funcBIRTHDAY;
	sigaction(12, &act, NULL);

	act.sa_handler = signalHandler;
	sigaction(3, &act, NULL);

	// if user's input is "KILL", then SIGTERM is sended
	sigaction(SIGTERM, &act, NULL);

	printf("my pid: %d\n", getpid());

	while(1) {
		sleep(1);
	}	
	return 0;
}
