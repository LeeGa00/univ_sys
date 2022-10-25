#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	int index, fd[2];
	pid_t pid1, pid2;

	for(int i = 0; i < argc; i++){
		if (strcmp("|", argv[i]) == 0){
			index = i;
			break;
		}
	}

	argv[index] = '\0';

	if(argc < 2)
		perror("input error\n");

	if(pipe(fd) < 0)
                perror("pipe error\n");

	if (!fork()) {
			 //child1
			close(1);
			dup2(fd[1], 1); //stout result -> pipe write
			close(fd[0]);

			execvp(argv[1], argv + 1);
		
	}else { //parent

		if (!fork()){ //child2
                        close(0);
                        dup2(fd[0], 0);
                        close(fd[1]);

                        execvp(argv[index+1], argv + index + 1);
                        exit(0);
                }

		close(fd[0]);
		close(fd[1]);

		wait(NULL);
		wait(NULL);
		printf("parent exit\n");
	}
}
