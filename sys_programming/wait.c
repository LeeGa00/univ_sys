#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
	pid_t pid;
	int status;

	if((pid = fork()) <0)
		perror("fork error");

	else if(pid == 0){
		printf("hi from child\n");
		exit(7);
	}
	
	else {
		//here, the parent will wait untill its child dies
		if(wait(&status) != pid)
			perror("wait error");

		printf("hi from parent\n");

		if(WIFEXITED(status))
			printf("normal, exit status = %d\n", WEXITSTATUS(status));
		else if(WIFSIGNALED(status))
			printf("abnormal,signal number = %d\n", WTERMSIG(status));
	}

	exit(EXIT_SUCCESS);
}
