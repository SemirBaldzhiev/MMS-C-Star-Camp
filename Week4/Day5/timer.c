#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    printf("%lu, %lu\n", tv1.tv_sec, tv1.tv_usec);
    pid_t pid = fork();
    if (pid == -1){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (pid == 0){
        

        execvp(argv[1], argv + 1);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }
    else{
        wait(NULL);
        gettimeofday(&tv2, NULL);
        printf("%lu, %lu\n", tv2.tv_sec, tv2.tv_usec);
        printf("Elapsed time: %lu\n", (tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec));
    }
    return EXIT_SUCCESS;
}
