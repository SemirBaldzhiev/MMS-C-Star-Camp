#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int main() {

    pid_t pid = fork();

    if (pid == -1){
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0){

    }
    else{
        
    }

    return EXIT_SUCCESS;
}