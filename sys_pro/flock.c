/* flock.c */
/* touch file-lock */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>

#define LOCK_PATH "file-lock"

int main(int argc, char **argv) {
	int fd, lock;

	if(argc < 2 || strlen(argv[1]) < 1){
		printf("Usage : ./flock ( x | s ) [ n ]\n");
		exit(EXIT_FAILURE);
	}

	// if x is set, we are going to have exclusive lock
	// otherwise, the shared lock is set
	lock = (argv[1][0] == 'x' ? LOCK_EX: LOCK_SH);

	// if n is set, we are goingn to have the non-blocking
	if (argc >= 3 && strlen(argv[2]) >= 1 && argv[2][0] == 'n')
		lock |= LOCK_NB;

	if ((fd = open(LOCK_PATH, O_RDONLY)) < 0) {
		perror("already locked");
		exit(1);
	}

	if (flock(fd, lock) < 0) {
		if (errno == EWOULDBLOCK){
			perror("already locked");
			exit(1);
		}
		else {
			perror("flock() error");
			exit(1);
		}
	}

	printf("lock acquired, sleeping... \n");

	sleep(10);

	if (flock(fd, LOCK_UN) < 0) {
		perror("flock() error");
		exit(1);
	}

	exit(EXIT_SUCCESS);
}


