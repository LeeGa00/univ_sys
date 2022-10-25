#include <stdlib.h>
#include <unistd.h>

int main(void) {
        pid_t pid;

        printf("before fork(): %d\n", getpid());

        if((pid = fork()) < 0)
                perror("error in fork\n");
        /* here, the child code part */
        else if(pid == 0){
                printf("hi! it's a child (%d -> %d)\n", getppid(), getpid());
        }
        /* here, the parent code part */
        else {
                sleep(3); // it makes the parent code lives longer
                printf("hi! it's a parent (%d)\n", getpid());
        }

        /* then, who is in charge of this? */
        printf("after fork(): who called this? %d\n", getpid());

        exit(EXIT_SUCCESS);
}
