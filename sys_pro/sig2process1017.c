#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig) {
	if (sig == SIGUSR1)
		printf("received sigusr1\n");
	else if (sig == SIGUSR2)
		printf("received sigusr2\n");
	else if (sig == SIGINT)
		printf("received SIGINT\n");
	else
		printf("else signal\n");
}

int main(int argc, char** argv){
	
	struct sigaction act;
	sigset_t sigset;

	int toPid = 0;

	printf("my pid: %d\n", getpid());

	act.sa_handler = sigHandler;
	sigemptyset(&act.sa_mask);
	sigprocmask(SIG_BLOCK, NULL, &sigset); 
	act.sa_flags = 0;
	
	sigaction(SIGUSR2, &act, NULL);

	scanf("%d", &toPid);
	printf("send to %d\n", toPid);

	if (toPid == 0) 
		printf("get error\n");
	else {
		kill(toPid, SIGUSR1);
		printf("sent\n");
	}

	sleep(10);
}
