/* mmap-sync.c */
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define FILE "msync.data"
#define FILE2 "log.data"

int main(void) {
	struct stat finfo;
	size_t w = 0;
	int fd, fd2;
	int pagesize;
	const char *text = "This code creates a file, creates a memory map, stores data into the file, and writes the data to the disk using msync()";

	// we get the page size
	if ((pagesize = sysconf(_SC_PAGE_SIZE)) < 0) {
		perror("sysconf() error");
		exit(1);
	}

	fd = open(FILE, (O_CREAT | O_TRUNC | O_RDWR),
			(S_IRUSR | S_IWUSR ));

	fd2 = open(FILE2, (O_CREAT | O_RDWR), (S_IRUSR | S_IWUSR ));

	if (fd < 0 || fd2 < 0) {
		perror("open() error");
		exit(1);
	}

	if (fstat(fd2, &finfo) < 0) {
		perror("fstat() error");
		exit(1);
	}

	// file offset is moved to the bytes of pagesize from the start of the file
	// in other words, file offset is set to the page size
	off_t lastoffset = lseek(fd, pagesize, SEEK_SET);

	w = write(fd, " ", 1);

	if (w != 1 ) {
		perror("write() error");
		exit(1);
	}

	void *address, *log_addr;
	off_t my_offset = 0;

	// now we make a memory mapping area having the page size
	address = mmap(NULL, pagesize, PROT_WRITE, MAP_SHARED, fd, my_offset);
	//log_addr = mmap(NULL, pagesize, PROT_WRITE, MAP_SHARED, fd, finfo.st_size);

	if (address == MAP_FAILED) {
		perror("mmap() error");
		exit(1);
	}

	// we copy the text to the memory mapping area
	// in other words, we move some data (text) into the file using memory mapping
	strncpy((char*) address, text, strlen(text));
	

	// use msync() to write changes to the file on the disk. 
	// MS_SYNC indicates the memory mapping area is synced with the disk
	if (msync(address, pagesize, MS_SYNC) < 0 || msync(log_addr, pagesize, MS_SYNC) < 0) {
		perror("msync() error");
		exit(1);
	}
	else 
		printf("%s\n","msync() completed successfully.");

	// free the memory mapping area
	munmap(address, pagesize);
	munmap(log_addr, pagesize);

	close(fd);
	close(fd2);
//	unlink("msync-1.data");

	return(0);
}

