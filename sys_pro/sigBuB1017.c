#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo) {
	printf("inside handler\n");
        if (signo == SIGINT)
		printf(" received SIGINT\n");
	else if(signo == SIGUSR1)
		printf("blocked\n");
	else
		printf("else signal: %d\n", signo);
	printf("end handler\n");
}

int main(int argc, char** argv){
        
        struct sigaction act;

	/* if signal come, do signalHandler */
        act.sa_handler = signalHandler;
	/* all signals are not blocked */
        sigemptyset(&act.sa_mask);
	/* ctrl+c is added */
	sigaddset(&act.sa_mask, SIGUSR1);
	/* SA_NOMASK: don't block signals while taking signal */
        act.sa_flags = 0;
	sigprocmask(SIG_SETMASK, &act.sa_mask, NULL);
        
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);

	kill(getpid(), SIGUSR1);
	//kill(getpid(), SIGINT);

	while(1)
		sleep(1);
}	


