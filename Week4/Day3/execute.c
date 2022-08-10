#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    printf("Hello\n");
    int pid = fork();

    if (0 == pid){
        execlp("ls", "ls", "-l", "-a", "execute.c", NULL);
    }
    else{

        pid_t pid2 = fork();

        if (0 == pid2){
            execlp("ping", "ping", "www.google.com", "-c", "3", NULL);
        }
        else{
            wait(NULL);
            wait(NULL);
            printf("bye bye\n");
        }
        
    }

    return 0;
}
