/* mmap-list.c */

#include "mmap-list.h"

int main(void) {
	struct list *l = NULL;
	pid_t pid;

	//initialize the list in memory
	if (list_init(1000) <0){
		perror("list_init error");
		exit(1);
	}

	// add 3 items in the list
	if ((l = list_add(l, 42)) == NULL
			|| (l = list_add(l,17)) == NULL
			|| (l = list_add(l,13)) == NULL) {
		perror("list_add error");
		exit(1);
	}

	//get (print) the items in the list
	list_visit("common", l);

	//now, we fork()
	if ((pid = fork()) < 0) {
		perror("fork() error");
		exit(1);
	}

	if(pid > 0) {
		l = list_add(l,7);

		list_visit("parent", l);
	}
	else {
		l = list_add(l, 5);

		list_visit("child", l);
	}

	exit(EXIT_SUCCESS);
}
