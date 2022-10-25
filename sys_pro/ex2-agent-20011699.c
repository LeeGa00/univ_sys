/* ex2-agent-20011699.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void) {
        int s_pid;
        char w_action[8];

        printf("pid: ");
        scanf("%d",&s_pid);
        getchar();
        printf("signal to send: ");
        scanf("%s", w_action);
	getchar();

        if(strcmp("id", w_action) == 0){
                kill(s_pid, SIGUSR1);
        } else if(strcmp("birthday", w_action) == 0) {
		kill(s_pid, SIGUSR2);
	} else if(strcmp("KILL", w_action) == 0) {
		kill(s_pid, SIGKILL);
	} else if(strcmp("QUIT", w_action) == 0) {
		kill(s_pid, SIGQUIT);
	}
}
