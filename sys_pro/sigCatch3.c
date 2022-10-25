#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigHandler(int sig) {
	sigset_t sigset;

	sigprocmask(SIG_SETMASK, NULL, &sigset);
	if (sigismember(&sigset, sig))
		printf("The signal(%d) is catched\n", sig);
}

int main(int argc, char** argv){
	
	struct sigaction act;

	if (argc > 4) {
		printf("input error\n");
		exit(1);
	}

	act.sa_handler = sigHandler;
	sigemptyset(&act.sa_mask);
	
	sigaddset(&act.sa_mask, atoi(argv[1]));
	sigaddset(&act.sa_mask, atoi(argv[2]));
	sigaddset(&act.sa_mask, atoi(argv[3]));

	act.sa_flags = 0;

	sigaction(atoi(argv[1]), &act, NULL);
	sigaction(atoi(argv[2]), &act, NULL);
	sigaction(atoi(argv[3]), &act, NULL);

	sleep(30);

	printf("program exit\n");

	return(0);
}

