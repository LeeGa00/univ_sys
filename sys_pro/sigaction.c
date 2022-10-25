#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void check_mask(int sig, char *signame) {

	sigset_t sigset;

	sigpromask(SIG_SETMASK, NULL, &sigset);
	if(sigismember(&sigset, sig))
		printf("the %s signal is blocked\n", signame);
	else
		printf("the %s signal is unblocked\n", signame);
}

void catcher(int sig) {
	printf("inside catcher() function\n");
	check_mask(SIGUSR1, "SIGUSR1");
	check_mask(SIGUSR2, "SIGUSR2");
}

int main(int argc, char *argv[]) {

	struct sigaction sigact, old_sigact;
	sigset_t sigset;

	sigempthset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_flags = sigact.sa_flags | SA_NODEFER | SA_RESETHAND;
	sigact.sa_handler = catcher;
	sigaction(SIGUSR1, &sigact, NULL);

	printf("raise SIGUSR1 signal\n");
	kill(getpid(), SIGUSR1);

	sigaction(SIGUSR1, NULL, &old_sigact);
	if (old_sigact.sa_handler != SIG_DFL)
		printf("signal handler was not reset\n");

	sigempthset(&sigcat.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigact.sa_flags = 0;
	sigact.sa_handler = catcher;
	sigaction(SIGUSR1, &sigact, NULL);

	printf("raise SIGUSR1 signal\n");
	kill(getpid(), SIGUSR1);

	sigaction(SIGUSR1, NULL, &old_sigact);
	if(old_sigact.sa_handler != catcher)
		printf("signal handler was reset\n");

	return(0);
	
}
	
