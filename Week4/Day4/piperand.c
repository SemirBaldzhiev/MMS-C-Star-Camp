#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int fd[2]; // fd[1] -> write, fd[0] -> read;
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (0 == pid){
        close(fd[0]);
        srand(time(NULL));
        int num = 1 + rand() % 100;
        write(fd[1], &num, sizeof(int));
        close(fd[1]);
    }
    else{
        close(fd[1]);

        int numFromChild;
        read(fd[0], &numFromChild, sizeof(int));
        close(fd[0]);
        wait(NULL);
        printf("Num: %d\n", numFromChild);
    }

    return 0;
}