#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int p2c[2], c2p[2];
	char buf1[30], buf2[30];

	if(pipe(p2c) == -1) {
		perror("pipe error");
	}

	if(pipe(c2p) < 0)
		perror("pipe c2p error");

	if(!fork()) { //child
		close(p2c[1]);
		close(c2p[0]);
		write(c2p[1], "from child", 11);
		read(p2c[0], buf1, 12);
		printf("child got from parent: %s!\n", buf1);

		exit(0);

	} else {
		close(p2c[0]);
		close(c2p[1]);
		write(p2c[1], "from parent", 12);
                read(c2p[0], buf2, 11);
                printf("parent got from child: %s!\n", buf2);

		wait(NULL);
	}

}
