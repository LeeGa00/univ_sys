#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "FIFO_FD"

int main(void)
{
	char buf[100];
	int num, fd;

	/* making a FD, which is the same one the writer uses, for FIFO */
	if(mknod(FIFO_NAME, S_IFIFO | 0666, 0) == -1)
		perror("mknod error");

	/* we are waiting for the writer */
	/* we open the FD, when the writer opens the FD */
	printf("Reader: waiting for a writer\n");
	fd = open(FIFO_NAME, O_RDONLY);

	printf("Reader: the writer ready.\n");

	/* Receive the data sent from the writer via FIFO */
	do {
		if ((num = read(fd, buf, 100)) == -1)
			perror("read error");
		else {
			buf[num] = '\0';
			printf("Reader: %d bytes read: %s", num, buf);
		}
	} while (num > 0);

	return 0;
}
