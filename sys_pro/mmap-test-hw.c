/* mmap-test.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
 
#define FILE "test.data"
 
// create a file and write some data
void create_data(void) {
	int fd, i;
	printf("%s\n", __func__);

	fd = open(FILE, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	for (i = 0; i < 10; i++)
		write(fd, &i, sizeof(int));

	close(fd);
}
 
// open the file and read/print the data inside
void display_data(void) {
	int fd = 0, data = 0, i;
	printf("%s\n", __func__);
 
	fd = open(FILE, O_RDONLY);

	for (i = 0; i < 10; i++)
		if (read(fd, &data, sizeof(int)) == 4)
			printf("%4d", data);

	puts("");

	close(fd);
}
 
// open the file and change the data inside
void change_data(void) {
	int fd, data;

	fd = open(FILE, O_RDWR);
	read(fd, &data, sizeof(int));

	data += 100;

	write(fd, &data, sizeof(int));
	close(fd);
}
 
// now we use memory mapping to map the file into memory
void mmap_data(void) {
	int *mapped = NULL;
	int fd;
	struct stat finfo;
 
	fd = open(FILE, O_RDWR);

	if(fstat(fd, &finfo) < 0) {
		perror("fstat() error");
		exit(1);
	}
 
	// size of memory mapped area is the size of the file
	mapped = mmap(NULL, finfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mapped == MAP_FAILED) {
		perror("mapp() error");
		exit(1);
	}
 
	// we save some data into the memory mapped area
	mapped[1] += 100;
	mapped[2] += 200;
	mapped[3] += 300;
 
	// use msync() to write changes to the file on the disk
	// MS_ASYNC indicates the memory mapping area is synced with kernel buffer cache
	msync(mapped, finfo.st_size, MS_ASYNC);

	// free the memory mapping area
	munmap(mapped, finfo.st_size);
 
	close(fd);
}
 
int main(void) {
	create_data();
	display_data();

	change_data();
	display_data();

	mmap_data();
	display_data();

	return 0;
}
