/* sigmal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* one handler for both signals */
static void sig_usr (int signo) {
	if (signo == SIGUSR1) printf("received SIGUSR1\n");
	else if(signo == SIGUSR2) printf("receied SIGUSR2\n");
}

int main(void) {
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) perror("can't catch SIGUSR1");
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) perror("can't catch SIGUSR2");
	for ( ; ; )
		sleep(60);

	return(0);
}
