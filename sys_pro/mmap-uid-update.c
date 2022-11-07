/* mmap-uid-update.c */

#include <stdio.h>
#include <stdlib.h>
#include "mmap-uid.h"

int main(void) { 
	int fd;
	struct stat finfo; 
	struct glob_id *id;

	if ((fd = open(DB_FILE, O_RDWR)) < 0) {
		perror("open() error");
		exit(1);
	}

	if (fstat(fd, &finfo) < 0) {
		perror("fstat() error");
		exit(1);
	}

	// We map the file into memory
	// Actually, we map the structure into memory via the file
	// Note that the mapped file is DB_FILE, which is also used by mmap-uid-init.c
	id = (struct glob_id *) mmap(NULL, finfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 

	if (id == MAP_FAILED) {
		perror("mmap() error");
		exit(1);
	}

	printf("checking magic number...\n");

	// We check the magic number
	if (glob_id_verify_magic(fd, id) < 0) { 
		printf("invalid magic number, abort!\n"); 
		exit(EXIT_FAILURE);
	}

	else {
		// We got the counter value
		printf("got id: %ld\n", id->val); 
		// We here increase the counter value
		glob_id_write(id, id->val + 1); 

		exit(EXIT_SUCCESS);
	}
}
