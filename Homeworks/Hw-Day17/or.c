#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int execute_cmd(char *cmd){

    pid_t pid = fork();
    int status;

    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (0 == pid) {
        execlp(cmd, cmd, NULL);
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
    }   

    return WEXITSTATUS(status);
}

int main(int argc, char **argv) {

    int exit_status = execute_cmd(argv[1]);
    if (EXIT_SUCCESS == exit_status){
        return exit_status;
    }

    exit_status = execute_cmd(argv[2]);
    return exit_status;
}
