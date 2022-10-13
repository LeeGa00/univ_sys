#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int pfd[2];

	if(pipe(pfd) == -1) {
		perror("pipe error");
	}

	if(!fork()){
		close(1);
		dup(pfd[1]);
		close(pfd[0]);
	}

}
