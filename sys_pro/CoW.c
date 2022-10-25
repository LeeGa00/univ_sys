#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int global = 100; // initialized data

int main(void){
	int var; // automatic variabble, local variable in the stack
	pid_t pid;
	
	var = 10;

	if((pid = fork()) < 0 )
		perror("error in fork\n");
	/* here, the child code part */
	else if(pid == 0){
		printf("hi! it's a child (%d)\n", getpid());
		global++;
		var++;
	}
	/* here, the parent code part */
	else{
		sleep(3);
		printf("hi! it's parent (%d)\n", getpid());
	}

	/* here, the following code part is the individual parts for the child and parent */
	printf("pid: %d, global: %d, var: %d\n", getpid(), global, var);

	exit(EXIT_SUCCESS);
}
