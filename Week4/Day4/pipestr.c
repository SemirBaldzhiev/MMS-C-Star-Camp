#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
        char *str = "Hello MMS C Camp 16";
        //int num = 1 + rand() % 100;
        unsigned len = strlen(str) + 1;
        write(fd[1], &len, sizeof(len));
        write(fd[1], str, len);
        close(fd[1]);
    }
    else{
        close(fd[1]);

        char childStr[200];
        unsigned str_len;
        read(fd[0], &str_len, sizeof(str_len));
        read(fd[0], childStr, str_len);
        close(fd[0]);
        wait(NULL);
        printf("Str: %s\n", childStr);
    }

    return 0;
}