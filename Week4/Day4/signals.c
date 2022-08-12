#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void handler(int sig){
    printf("\nBye Bye. Have a nice day!\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSER1, sa, NULL);
    while (1);
    return EXIT_SUCCESS;
}