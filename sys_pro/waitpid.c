#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int n_system(const char *cmd) {
	pid_t pid;
	int status;

	if (cmd == NULL)
		return(1); // no signal management

	if ((pid = fork()) < 0)
		status = 0; // fork() error
	else if (pid == 0) {
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		_exit(127); //execl() error
	}
	else {
		while (waitpid(pid
