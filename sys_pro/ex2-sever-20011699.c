/* ex2-sever-20011699.c */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

pid_t pid_id, pid_bir;

int sigHandler(int sig) {
	int status, p[2];
	char buf[30];
	
	if (pipe(p) < 0){
		perror("piepe error");
		exit(1);
	}

	printf("test id bir : %d %d\n", pid_id, pid_bir);

        if (sig == SIGUSR1){
		if ( pid_id < 0){
			pid_id = fork();

			if(pid_id < 0){
				perror("fork error");
				exit(1);
			}
		}
		
		if (pid_id = 0) {
			write(p[1], "my id : 20011699", 16);
			exit(0);			
		} else {
			read(p[0], buf, 16);
			printf("%s\n", buf);

			waitpid(pid_id, &status, NULL);
		}
	}
	else if (sig == SIGUSR2) {
		if ( pid_bir = -1 ){
                        pid_bir = fork();

                        if(pid_bir < 0)
                                perror("fork error");
                }

                if (pid_bir = 0) {
                        write(p[1], "my birthday : 12.17", 19);

                } else {
                        read(p[0], buf, 19);
                        printf("%s\n", buf);
                }
	}else if (sig == SIGQUIT){
	       printf("NO QUIT\n");
	}
	return 0;	
}

int main(int argc, char** argv){

        struct sigaction act;

        int p[2];

	pid_id = pid_bir = -1;

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
