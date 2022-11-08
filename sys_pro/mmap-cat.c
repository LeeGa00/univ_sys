/* mmap-cat.c */
/* gcc -o mmap-cat mmap-cat.c */
/* ./mmap-cat mmap-cat.c */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <sys/mman.h> 
#include <sys/stat.h> 
#include <unistd.h> 

int main(int argc, char **argv) { 
	int fd; // file descriptor
	struct stat finfo; // file information structure
	void *buf; // buffer

	if (argc != 2) {
		perror("Usage: mmap-cat filename");
		exit(1);
	}

	// we open the file with the read only permission
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		perror("open() error");
		exit(1);
	}

	// we get the file information in finfo via fstat()
	// man 2 fstat
	if (fstat(fd, &finfo) < 0) {
		perror("fstat() error");
		exit(1);
	}

	// we now use mmap() to map the file in memory
	// we get the file data into the buffer
	buf = mmap(NULL, finfo.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	if (buf == MAP_FAILED) {
		perror("mmap() error");
		exit(1);
	}

	// we write (print) the file data
	if (write(STDOUT_FILENO, buf, finfo.st_size) != finfo.st_size) {
		perror("write() error");
		exit(1);
	}

	munmap(buf, finfo.st_size);
	close(fd);

	exit(EXIT_SUCCESS); 
}
