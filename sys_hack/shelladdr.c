#include <stdio.h>

int main(void) {
	long systemaddr = 0x7ffff7a31420;
	long shelladdr;

	while(memcmp((void*)systemaddr, "/bin/sh", 8))
		systemaddr++;

	shelladdr = systemaddr;
	printf("/bin/sh = %p\n", shelladdr);

	return(0);
}
