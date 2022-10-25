/* ex2-sever-20011699.c */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int sigHandler(int sig) {
        if (sig == SIGUSR1){
		if(!fork()){
			printf("my id : 20011699\n");
		} else {
			wait(NULL);
		}
	}
	else if (sig == SIGUSR2) {
		if (!fork())
			printf("my birthday : 2001.12.17\n");
		else
			wait(NULL);
	}else if (sig == SIGQUIT){
	       printf("NO QUIT\n");
	}	       
}

int main(int argc, char** argv){

        struct sigaction act;

        int toPid = 0;

        printf("my pid: %d\n", getpid());

        act.sa_handler = sigHandler;
        sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
	//SIGKILL can't be handled
	
	while(1)
		sleep(1);

}
