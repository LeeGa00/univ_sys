/* mmap-uid-init.c */

#include <stdio.h>
#include <stdlib.h>
#include "mmap-uid.h"

int main(void) {
	int fd;
	struct stat finfo;
	struct glob_id *id;

	if ((fd = open(DB_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR )) < 0) {
		perror("open() error");
		exit(1);
	}

	// We are using ftruncate() to make the filesize is 
	// to be truncated to sizeof(struct glob_id)
	// On success, 0 is returned; on error, -1 is returned
	if (ftruncate(fd, sizeof (struct glob_id)) < 0) {
		perror("ftruncate() error");
		exit(1);
	}

	if (fstat(fd, &finfo) < 0) {
		perror("fstat() error");
		exit(1);
	}

	// We map the file into memory
	// Actually, we map the structure into memory via the file
	id = (struct glob_id *) mmap(NULL, finfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (id == MAP_FAILED) {
		perror("mmap() error");
		exit(1);
	}

	// We call the function to initialize the counter value with 0
	glob_id_write(id, (long) 0);

	exit(EXIT_SUCCESS);
}
