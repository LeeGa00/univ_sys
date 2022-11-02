/* mmap-ipc2.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(void) {
	int len=1024*1024; // 1MB

	void *addr = mmap((void *)0, len, /* address and data size (bytes) */
			PROT_READ+PROT_WRITE, /* access flags */
			MAP_ANONYMOUS+MAP_SHARED, /* type flags */
			-1, 0); /* file descriptor (not needed) and file offset */

	if (addr == MAP_FAILED) {
		perror("mmap() error"); 
		exit(1);
	}

	int *buf=(int *)addr; /* make mmap'd region into an int pointer */

	buf[3] = 7;
	buf[2] = buf[3];

	printf("mmap returned %p, which seems readable and writable\n", addr);
	printf("data in memory: %d\n", buf[0]);
	printf("data in memory: %d\n", buf[1]);
	printf("data in memory: %d\n", buf[2]);
	printf("data in memory: %d\n", buf[3]);
	printf("data in memory: %d\n", buf[4]);

	// to remove physical memory from a given location in virtual memory
	munmap(addr,len);

	return 0;
}
