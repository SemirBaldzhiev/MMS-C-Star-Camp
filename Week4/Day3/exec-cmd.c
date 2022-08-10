#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    
    for (int i = 1; i < argc; i++){
        pid_t pid = fork();

        if (-1 == pid) {
            exit(EXIT_FAILURE);
        }

        if (0 == pid){
            execlp(argv[i], argv[i], NULL);
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 1; i < argc; i++){
        wait(NULL);
    }

    return 0;
}